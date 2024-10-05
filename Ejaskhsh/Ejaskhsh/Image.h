#pragma once
#include <string>
//... ’λλα header files, ανάλογα τι λείπει από κάθε πλατφόρμα.
#include "ppm.h"
#include "ImageStorageTraits.h"

namespace graphics
{
	// κληρονομεί από την ImageStorageTraits:
	class Image : public ImageStorageTraits
	{

	public:
		// ---------------- Test1 ---------------------------------------

		// Δεν κάνει τίποτα ο default ctor, αλλά πρέπει να υπάρχει, γιατί οι 
		// άλλοι ctors τον καταργούν
		Image()
		{
		}

		// Κατασκευαστής αρχικοποίησης εικόνας σε συγκεκριμένες διαστάσεις
		Image(int w, int h)
		{
			width = w;
			height = h;

			// sanity check για να μη μας πετάξει σφάλμα το allocation (προαιρετικό)
			// Αν έστω και ένα είναι 0, δεν είναι σωστή η εικόνα.
			if (height * width == 0)
				return;

			data = new unsigned char[3 * height * width];

			// Προαιρετικό: καθαρισμός της εικόνας
			memset(data, 0, 3 * height * width);
		}

		// Τελεστής πρόσβασης σε στοιχείο. Επιστρέφει δείκτη στο τρέχον pixel,
		// Χρησιμοποιεί απευθείας την δεδομένη μέθοδο που κληρονομείται.
		unsigned char* operator () (unsigned int x, unsigned int y)
		{
			if (data)
				return pixel(x, y);
			else
				return nullptr;
		}

		// By-the-book (and slides) τελεστής αντιγραφής με deep copy.
		Image& operator = (const Image& orig)
		{
			if (&orig == this)
				return *this;
			if (data)
				delete[] data;

			width = orig.width;
			height = orig.height;

			if (height * width == 0)
				return *this;

			data = new unsigned char[3 * height * width];
			memcpy(data, orig.data, 3 * height * width);

			return *this;
		}

		// Τελεστής ελέγχου ισοτιμίας
		bool operator == (const Image& right)
		{
			// Γρήγορος πρώτος έλεγχος
			if (width != right.width || height != right.height)
				return false;

			// Προαιρετικός έλεγχος ασφαλείας - 2 κενές εικόνες τις δεχόμαστε ως ίσες.
			if (data == nullptr && right.data == nullptr)
				return true;

			// Έλεγχος ασφαλείας
			if (data == nullptr || right.data == nullptr)
				return false;

			// Έλεγχος σημείο προς σημείο
			for (size_t i = 0; i < 3 * width * height; i++)
			{
				if (right.data[i] != data[i])
					return false;
			}
			return true;
		}

		// κλασικός by-the-slides κατασκευαστής αντιγραφής για deep copy
		Image(const Image& orig)
		{
			if (orig.height * orig.width == 0)
				return;

			width = orig.width;
			height = orig.height;
			data = new unsigned char[3 * height * width];
			memcpy(data, orig.data, 3 * height * width);

		}

		// Κλασικός καταστροφέας. Ελέγχει αν έχουν δεσμευθεί δεδομένα και τα αποδεσμεύει.
		~Image()
		{
			if (data)
				delete[] data;
		}

		// ---------------- Test2 ---------------------------------------


		// φόρτωμα εικόνας χρησιμοποιώντας έτοιμο κώδικα που δίνεται.
		bool load(std::string filename)
		{
			// έλεγχος για το αν ήδη υπάρχουν δεδομένα. Διαγράφονται αν υπάρχουν,
			// καθώς μας έρχεται νέος buffer.
			if (data)
				delete[] data;

			bool loaded = (data = ReadPPM(filename, &width, &height));

			if (!loaded)
			{
				width = height = 0;
				return false;
			}
			return true;
		}

		// Σύμφωνα με τις προδιαγραφές επιστροφής ορίσματος των Test2,3,
		// επιστρέφει τις διαστάσεις σε ένα ζεύγος std::pair<>
		std::pair<int, int> getDimensions()
		{
			return std::pair<int, int>(width, height);
		}


		// αποθήκευση εικόνας χρησιμοποιώντας έτοιμο κώδικα που δίνεται.
		bool save(std::string filename)
		{
			if (data) // δεν έχει νόημα να σώσουμε κενή εικόνα.
			{
				return WritePPM(data, width, height, filename);
			}
			return false;
		}

		// ---------------- Test3 ---------------------------------------

		// Τελεστής μετατροπής της εικόνας σε unsigned char * 
		// για να μπορέσουμε να περάσουμε τα δεδομένα της στην encrypt/decrypt της Codec,
		// όπως ζητείται στην Test3
		operator unsigned char* ()
		{
			return data;
		}

		// Τελεστής "γεμίσματος" της εικόνας από εξωτερικό Unsigned char buffer.
		// Προαιρετικό: επιστροφή Image &
		Image& operator << (const unsigned char* const buffer)
		{
			// Προαιρετικό - sanity check
			if (!buffer || width * height == 0)
				return *this;

			// Προαιρετικό - θα πρέπει η εικόνα να έχει αρχικοποιηθεί με τις 
			// σωστές διαστάσεις έτσι κι αλλιώς:
			if (!data)
				data = new unsigned char[3 * width * height];

			// Υποχρεωτικό: πέρασμα των στοιχείων του buffer στο data.
			memcpy(data, buffer, width * height * 3);
			return *this;
		}

		// By-the-book (and slides) move assignement op. για το Test3
		Image& operator = (Image&& orig)
		{
			if (&orig == this)
				return *this;
			if (data)
				delete[] data;

			width = orig.width;
			height = orig.height;

			if (height * width == 0)
				return *this;

			data = orig.data;
			orig.data = nullptr;
			orig.width = 0;
			orig.height = 0;

			return *this;
		}

	};
}
