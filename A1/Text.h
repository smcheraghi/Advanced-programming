#ifndef TEXT_H
#define TEXT_H

class Text
{
private:
	char* pStore{ nullptr };								//Points to storage of the C-string in this object 
	int textLength{ 0 };									//Length of the text
public:
	virtual ~Text(); 										//Releases dynamic storage in use by this object 
	Text();													//Default constructor; equivalent to Text ("")
	Text(const Text& txt);									//Copy Constructor; deep-copies txt into the object being constructed
	Text(const char* pCstr);								//Conversion Constructor (C-string to Text)
	void assign(const char* pCstr);							//Assigns a C-string to this object, replacing its current contents
	void assign(const Text& txt);							//Assigns a Text object to this object, replacing its current contents
	Text &operator=(const Text& txt);						//Assignment operator= overload. Assigns the right hand side operand to this object, replacing its current contents
	void append(const char* pCstr);							//Appends a C-string to this object, extending its contents
	void append(const Text& txt);							//Appends txt's text to this object, extending its contents
	void clear();											//Erases the contents of the C-string in this object, which becomes an empty C-string
	int length() const;										//Returns the length of this object's text
	bool isEmpty() const;									//Determines whether this object represents a C-string of length zero	
	const char* getCstring() const;							//returns pStore as a const pointer
};
std::ostream& operator<<(std::ostream&, const Text&);		// overload operator << 
#endif 
