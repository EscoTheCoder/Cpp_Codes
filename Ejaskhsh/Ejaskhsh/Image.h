#pragma once
#include <string>
//... ���� header files, ������� �� ������ ��� ���� ���������.
#include "ppm.h"
#include "ImageStorageTraits.h"

namespace graphics
{
	// ���������� ��� ��� ImageStorageTraits:
	class Image : public ImageStorageTraits
	{

	public:
		// ---------------- Test1 ---------------------------------------

		// ��� ����� ������ � default ctor, ���� ������ �� �������, ����� �� 
		// ����� ctors ��� ���������
		Image()
		{
		}

		// ������������� ������������� ������� �� ������������� ����������
		Image(int w, int h)
		{
			width = w;
			height = h;

			// sanity check ��� �� �� ��� ������� ������ �� allocation (�����������)
			// �� ���� ��� ��� ����� 0, ��� ����� ����� � ������.
			if (height * width == 0)
				return;

			data = new unsigned char[3 * height * width];

			// �����������: ���������� ��� �������
			memset(data, 0, 3 * height * width);
		}

		// �������� ��������� �� ��������. ���������� ������ ��� ������ pixel,
		// ������������ ��������� ��� �������� ������ ��� �������������.
		unsigned char* operator () (unsigned int x, unsigned int y)
		{
			if (data)
				return pixel(x, y);
			else
				return nullptr;
		}

		// By-the-book (and slides) �������� ���������� �� deep copy.
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

		// �������� ������� ���������
		bool operator == (const Image& right)
		{
			// �������� ������ �������
			if (width != right.width || height != right.height)
				return false;

			// ������������ ������� ��������� - 2 ����� ������� ��� ��������� �� ����.
			if (data == nullptr && right.data == nullptr)
				return true;

			// ������� ���������
			if (data == nullptr || right.data == nullptr)
				return false;

			// ������� ������ ���� ������
			for (size_t i = 0; i < 3 * width * height; i++)
			{
				if (right.data[i] != data[i])
					return false;
			}
			return true;
		}

		// �������� by-the-slides ������������� ���������� ��� deep copy
		Image(const Image& orig)
		{
			if (orig.height * orig.width == 0)
				return;

			width = orig.width;
			height = orig.height;
			data = new unsigned char[3 * height * width];
			memcpy(data, orig.data, 3 * height * width);

		}

		// �������� ������������. ������� �� ����� ��������� �������� ��� �� �����������.
		~Image()
		{
			if (data)
				delete[] data;
		}

		// ---------------- Test2 ---------------------------------------


		// ������� ������� ��������������� ������ ������ ��� �������.
		bool load(std::string filename)
		{
			// ������� ��� �� �� ��� �������� ��������. ������������ �� ��������,
			// ����� ��� ������� ���� buffer.
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

		// ������� �� ��� ������������ ���������� ��������� ��� Test2,3,
		// ���������� ��� ���������� �� ��� ������ std::pair<>
		std::pair<int, int> getDimensions()
		{
			return std::pair<int, int>(width, height);
		}


		// ���������� ������� ��������������� ������ ������ ��� �������.
		bool save(std::string filename)
		{
			if (data) // ��� ���� ����� �� ������� ���� ������.
			{
				return WritePPM(data, width, height, filename);
			}
			return false;
		}

		// ---------------- Test3 ---------------------------------------

		// �������� ���������� ��� ������� �� unsigned char * 
		// ��� �� ���������� �� ��������� �� �������� ��� ���� encrypt/decrypt ��� Codec,
		// ���� �������� ���� Test3
		operator unsigned char* ()
		{
			return data;
		}

		// �������� "����������" ��� ������� ��� ��������� Unsigned char buffer.
		// �����������: ��������� Image &
		Image& operator << (const unsigned char* const buffer)
		{
			// ����������� - sanity check
			if (!buffer || width * height == 0)
				return *this;

			// ����������� - �� ������ � ������ �� ���� ������������� �� ��� 
			// ������ ���������� ���� �� ������:
			if (!data)
				data = new unsigned char[3 * width * height];

			// �����������: ������� ��� ��������� ��� buffer ��� data.
			memcpy(data, buffer, width * height * 3);
			return *this;
		}

		// By-the-book (and slides) move assignement op. ��� �� Test3
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
