#include <iostream>
#include <string>

#define BUFFER_SIZE 200

#define ERR_ALLOC "Allocation failed"

class MyString {
private:
	int length;
	char* buffer;
public:
	MyString() {
		this->alloc(0);
	}

	MyString(int _length) {
		this->alloc(_length);
	}

	MyString(int _length, char* _str) {
		this->alloc(_length);
		for (int i = 0; i < _length; ++i) {
			this->buffer[i] = _str[i];
		}
	}

	void alloc(int length) {
		this->length = length;
		this->buffer = new char[this->length];
		if (!this->buffer) {
			std::cout << ERR_ALLOC << std::endl;
			delete[] this->buffer;
			exit(1);
		}
	}

	void input() {
		char* buffer = new char[BUFFER_SIZE + 1];
		int i = 0;
		do {
			buffer[i] = getc(stdin);
			++i;
		} while (buffer[i - 1] != EOF && buffer[i - 1] != '\n' && i < BUFFER_SIZE);
		if (i != BUFFER_SIZE)
			--i;
		this->alloc(i);
		for (i = 0; i < this->length; ++i) {
			this->buffer[i] = buffer[i];
		}
		delete[] buffer;
	}

	void output() {
		for (int i = 0; i < this->length; ++i) {
			std::cout << this->buffer[i];
		}
	}

	char getSymbol(int index) {
		return this->buffer[index];
	}

	int find(char c) {
		int i = 0;
		while (i < this->length) {
			if (this->buffer[i] == c)
				return i;
			++i;
		}
		return -1;
	}

	int rfind(char c) {
		int i = this->length;
		while (i >= 0) {
			if (this->buffer[i] == c)
				return i;
			--i;
		}
		return -1;
	}

	void erase(int leftIndex, int rightIndex) {
		if (rightIndex >= leftIndex && leftIndex >= 0 && rightIndex < this->length) {
			char* tmp = new char[this->length - (rightIndex - leftIndex) - 1];
			for (int i = 0, j = 0; i < this->length; ++i) {
				if (i < leftIndex || i > rightIndex) {
					tmp[j] = this->buffer[i];
					++j;
				}
			}
			this->length = this->length - (rightIndex - leftIndex) - 1;
			std::swap(this->buffer, tmp);
			delete[] tmp;
		}
	}

	MyString substr(int leftIndex, int rightIndex) {
		MyString newStr;
		if (rightIndex >= leftIndex && leftIndex >= 0 && rightIndex < this->length) {
			char* tmp = new char[rightIndex - leftIndex + 1];
			for (int i = leftIndex; i <= rightIndex; ++i) {
				tmp[i - leftIndex] = this->buffer[i];
			}
			newStr.length = rightIndex - leftIndex + 1;
			std::swap(newStr.buffer, tmp);
		}
		return newStr;
	}

	void push_back(char c) {
		char* tmp = new char[this->length + 1];
		for (int i = 0; i < this->length; ++i) {
			tmp[i] = this->buffer[i];
		}
		tmp[this->length] = c;
		this->length += 1;
		std::swap(this->buffer, tmp);
		delete[] tmp;
	}

	void pop_back() {
		this->erase(this->length - 1, this->length - 1);
	}

	MyString append(char c) {
		MyString newStr;
		newStr.alloc(this->length + 1);
		for (int i = 0; i < this->length; ++i) {
			newStr.buffer[i] = this->buffer[i];
		}
		newStr.buffer[newStr.length - 1] = c;
		return newStr;
	}

	MyString append(MyString str) {
		MyString newStr;
		newStr.alloc(this->length + str.length);
		for (int i = 0; i < this->length; ++i) {
			newStr.buffer[i] = this->buffer[i];
		}
		for (int i = this->length; i < newStr.length; ++i) {
			newStr.buffer[i] = str.buffer[i - this->length];
		}
		return newStr;
	}

	bool is_equals(MyString str) {
		if (this->length != str.length)
			return false;
		for (int i = 0; i < this->length; ++i)
			if (this->buffer[i] != str.buffer[i])
				return false;
		return true;
	}

	void clear() {
		this->length = 0;
		delete[] this->buffer;
		this->buffer = new char[this->length];
	}
};

int main() {
	//std::cin >> b;
	MyString a, b;
	//a.input();
	//b.input();
	//std::swap(a, b);
	//a.erase(1, 3);
	//a = a.substr(1, 3);
	//a = a.append('s');
	//a.push_back('g');
	//a = a.append(b);
	//a.output();
	std::cout << std::endl;
	return 0;
}