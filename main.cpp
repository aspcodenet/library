#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

class Book
{
public:
	Book(std::string id, std::string name, std::string author)
	{
		this->id = id;
		this->name = name;
		this->author = author;
		numberTotal = 0;
		numberBorrowed = 0;
	}
	~Book()
	{
		std::cout << this->name << " tas bort" << std::endl;
	}
	std::string GetTitle()
	{
		return name;
	}
	std::string Getid()
	{
		return id;
	}
private:
	std::string id;
	std::string name;
	std::string author;
	int numberTotal;
	int numberBorrowed;
};

class Library
{
public:
	Library()
	{

	}
	void CreateBook(std::string id, std::string name, std::string author)
	{
		Book *book = new Book(id, name, author);
		AddBook(book);
	}
	
	~Library()
	{
		for (int i = 0; i < _books.size(); i++)
			delete _books[i];
	}
	int GetCount()
	{
		return _books.size();
	}
	Book *GetBook(int index)
	{
		return _books[index];
	}
	Book *FindBook(std::string id)
	{
		for (int i = 0; i < _books.size(); i++)
			if (_books[i]->Getid() == id)
				return _books[i];
		return nullptr;
	}
private:
	void AddBook(Book *book)
	{
		_books.push_back(book);
	}


	std::vector<Book *> _books;
};

void TestLibrary()
{
	Library library;
	library.CreateBook("233", "Kalle och detektiverna", "Nils Nilsson");
	library.CreateBook("123", "Lisas kokbok", "Lisa Persson");
}

int main231231()
{
	//Book *aBook = new Book("111", "Hej", "Nisse");
	//std::cout  << aBook->GetTitle();
	//delete aBook;
	TestLibrary();
	return 0;
}










void TestLibrary2(Book *b)
{
	Library library;
	library.AddBook(b);
	library.CreateBook("233", "Kalle och detektiverna", "Nils Nilsson");
	library.CreateBook("123", "Lisas kokbok", "Lisa Persson");

}


int main()
{
	Book *b = new Book("111", "C++ for pros", "IOT18klassen");
	std::cout << b->GetTitle();
	TestLibrary2(b);
	std::cout << b->GetTitle();
	return 0;
}

int main111()
{
	//https://embeddedartistry.com/blog/2017/2/28/migrating-from-c-to-c-null-vs-nullptr
	Book *p = NULL;
	Book *p2 = nullptr;
	if (p2 == NULL)
	{
		std::cout << "p2 is null" << std::endl;
	}
	if (p == nullptr)
	{
		std::cout << "p is nullptr" << std::endl;
	}
	return 0;

}






