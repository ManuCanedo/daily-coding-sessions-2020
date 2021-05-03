#include <iostream>

class Parent {
public:
	virtual void whoru()
	{
		std::cout << "I am a " << m_Name << std::endl;
	}

private:
	std::string m_Name{ "Parent" };
};

class Sister : public Parent {
public:
	virtual void whoru()
	{
		std::cout << "I am a " << m_Name << std::endl;
	}

private:
	std::string m_Name{ "Sister" };
};

class Brother : public Parent {
public:
	virtual void whoru()
	{
		std::cout << "I am a " << m_Name << std::endl;
	}

private:
	std::string m_Name{ "Brother" };
};

main()
{
	Parent parent;
	Brother brother;
	Sister sister;

	// Polimorphism
	Parent* pP = &brother;
	pP->whoru();

	// Casting (forcing a type)
	Sister* pS = static_cast<Sister*>(&parent);
	pS->whoru(); // Calling a method after such a cast may cause the program to crash

	// Casting (forcing a type but it makes sense)
	Parent* pParentSister = &sister;
	Sister* pSisterStatic = static_cast<Sister*>(pParentSister);
	pSisterStatic->whoru();

	// Casting (safer cast using dyinamic checking)
	Sister* pSisterDynamic = dynamic_cast<Sister*>(pParentSister);
	if (pSisterDynamic != nullptr)
		pSisterDynamic->whoru();
	else
		std::cout << "Invalid cast!" << std::endl;

	// Casting to a rvalue reference
	Sister&& rvalRefSister = static_cast<Sister&&>(sister);
	rvalRefSister.whoru();

	// Extreme forced casts
	Sister* pSisterReinterpret = reinterpret_cast<Sister*>(&brother);
	float myFloat{ 5.2 };
	Brother* pBrotherReinterpret = reinterpret_cast<Brother*>(&myFloat);

	return 0;
}
