
#include <iostream>

using namespace std;

class A{
	private:
		void private_m_a(){cout << "private_m_a aus A " << endl; }
	protected:
		void protected_m_a(){cout << "protected_m_a aus A " << endl; }
	public:
		void public_m_a(){cout << "public_m_a aus A " << endl; }
};
class B : public A{//so machen wir es typischerweise
	private:
			int i;
	public:
		void m(){
			/*
			A a;
			B b;
			//a.private_m_a();//error
			//a.protected_m_a();//error
			this->protected_m_a();//ok
			b.protected_m_a();//ok
			a.public_m_a();//ok
			*/
		}
	void test(){
		/*
		this->i = 100;
		B b;
		b.i = 19;
		b.m();*/
	}
	
};
class C : protected A{
	/*
	protected:
	public_m_a
	*/
	
	
};

class D : private A{
	
};

class F : /*default??*/ protected   A{ //Was wird standard mässig benutzt
	void m() {
		//this->private_m_a();
		this->protected_m_a();//ok
		this->public_m_a();
		
	}
public:
	//using A::protected_m_a;
};


class FF : public F { //Was wird standard mässig benutzt
	void m() {
		//this->private_m_a();
		this->protected_m_a();//error
		this->public_m_a();//error

	}
};


class C_derived : protected C{
	public:
		void m(){
			public_m_a();
		}
};
/**
Base							Derived				public vererbung 		protected Vererbung 		private Vererbung   default
public													public				protected					private				
protected												protected 			protetcted					private
private													---					----						---
	
*/

int main(){
	A a;
		//a.private_m_a();//error
		//a.protected_m_a();//error
		a.public_m_a();//ok
	B b; 
		//b.private_m_a();//error
		//b.protected_m_a();//error
		b.public_m_a();//ok
	C c;
		//c.private_m_a();//error
		//c.protected_m_a();//error
		//c.public_m_a();//error, da diese Methode in C per protected Vererbung die Zurgriffskontrolle protected hat
//	D d;
	FF f;
	F* ap = &f;

	return 0;
}