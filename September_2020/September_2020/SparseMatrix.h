#pragma once
#include "SparseMatrixTraits.h"
#include <map>
#include <iostream>

using namespace std;

/* H SparseMatrix ���������� ��� SparseMatrixTraits ��� ����� ���
   ���� templated �� �� ���� template argument.
*/
template <typename T>
class SparseMatrix : public SparseMatrixTraits<T>
{
protected:

	/* ��������� ��� 1 - 1 ������������� ������ �������������
	   ����� ���� ���� ����� ������ ��� ��� ����������� �����,
	   � ��� �������� ��������� ��������� ������ �� �������������
	   �� ����� ���� ������� ����� ��� STL ��� ����� ������� ����
	   ��� ������������ ������ ���� �������� (��� ����� Coordinate)
	   ��� ����� (��� ����� �).

	   ��� ����� �� ��������� ������� ��� STL: unordered_map ��� map.
	   �� ��� ����������� �� "multimap" ����������, ����� �� ����
	   ���� ������� ��� ������� ��������. � map ���� �������� ��
	   ����������� �� ��������� �� �������� ��� ���������, �����
	   ���� �� �� ����������� ��� ��������, �� �� ������ ������.

	   ��������� ��� � ���� ���� ������ ��� ��� �������� ��� ���������
	   (operator () �� ��������� �� ������� �����) ��������� �� �� ����
	   Coordinates, � ����� ��� ������� ��������� ���������
	   (operator <) ��� ��� � std::map<Coordinates, T> ����� ��
	   ������������ �� �������� ��� ��� �������, �������� ��� default
	   ����� less().
	*/
	std::map<Coordinates, T> data;

public:

	// Fix the friend ostream& operator<< for SparseMatrix
	friend std::ostream& operator<< (std::ostream& os, const SparseMatrix& matrix) {
		for (const auto& item : matrix.data) {
			os << item.first << ": " << item.second << std::endl;
		}
		return os;
	}

	/* ���������� ������� �������, ��� �� ������ �� �������������� ����
	   � ������ ��� �������� ���� ��������� ���� ������. �� ��� �������
	   �� �������� ��� ���� pos ���� ������, ������ �� ���������� ��
	   "default" (��������) ��������, ��� �� ���� �� ���� ������� ���
	   getNullElement<T>(). �� ������ ���� ���������, �� ����������
	   �������� ��� �� ������������ ������� �� ���� �������, �� ����������
	   �� ��������� ������ ��������. ��� ����, ���� ��� �������������
	   ���������, ���� ������ �� ������� �� ���� ������ �� "��������"
	   �������� ������ ����� ��� ���� ��� ������ ����� �������� �����,
	   ���� ����� � ��������� ���� default �����.
	*/
	const T& operator () (Coordinates pos) const override
	{
		auto elem = data.find(pos);
		cout << elem->first<<" "<<elem->second<<endl;
		if (elem != data.end())
		{
			return elem->second;
		}
		else
			return getNullElement<T>();
	}

	/* � ������ ��� �perator () ��� ���������� ���� ������� �� ��������� ��������
	   ����� � ��������� �� �������������� ��� ������ ���������, ���� ��� ���������
	   �� ������� ��� ������� ���������� ��� �� ��� ��������� �� �����������
	   (��. main). ��������, � ������� ���� ������ �� ������� ��� ��� ����
	   ����������, ���� ��� ��������� ���������, ����� �� �� ������ � ������������
	   ��� ������� ��� map, ����������� ��� ������������ ���� ��� ��������.
	*/
	T& operator () (Coordinates pos) override
	{
		auto elem = data.find(pos);
		if (elem != data.end())
		{
			return elem->second;
		}
		else
		{
			data[pos] = T();
			return data[pos];
		}
	}

	void clear() override
	{
		data.clear();
	}

	/* �� ���������� �� ������� ���� ��� �� �� ������������ ���������.
	*/
	SparseMatrix() : SparseMatrixTraits<T>() {}

	SparseMatrix(const SparseMatrix& other) {
		data = other.data;
	}


	/* ����������� �� ��� ������������ �������� ��� ���� �� ��������� ��
	   �����������.
	*/
	void print() override
	{
		for (auto item : data)
		{
			std::cout << "\n";
			std::cout << "(" << item.first.row << ", " << item.first.col << "): " << item.second << " ";
		}
	}

	bool operator == (const SparseMatrix& right)
	{
		/* ��� ��� ������� 2 �������, ��������� ����� �� ��������: �� ����� ����
		   ������ ���������.
		*/
		if (right.data.size() != data.size())
			return false;

		/* ��� ��� ������ �������� ��� ���������, �������� �� ��������������� ���
		   ������� ��� ��������. ������� ��� ������ ����������,
		   ����� ����������� �� �������� ��� ���� SparseMatrix �� ���� �� �������
		   ��� ���� ��� �������� �� ���� ��� �����. � ���������� ��������� �����
		   ���������� ����� ��������� � ���� ������� �� ����� ���������� ��� �����.
		*/
		for (auto item : data)
		{
			if (operator() (item.first) != right(item.first))
				return false;
		}

		for (auto item : right.data)
		{
			if (operator() (item.first) != right(item.first))
				return false;
		}

		return true;
	}

};