
#include <iostream>

using namespace std;

class A{
	private:
		void private_m_a(){cout << "private_m_a aus A " << endl; }
	protected:
		void protected_m_a(){cout << "protected_m_a aus A " << endl; }
	public:
		virtual void public_m_a() { cout << "public_m_a aus A " << endl; }
		void public_m_a(int i) { cout << "public_m_a aus A " <<i<< endl; }
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
			cout << "m aus B" << endl;
		}
	void test(){
		/*
		this->i = 100;
		B b;
		b.i = 19;
		b.m();*/
	}
	//void public_m_a() { cout << "public_m_a aus B "  << endl; }

};
class C : public  B{
	/*
	protected:
	public_m_a
	*/
public:
	void public_m_a() { cout << "public_m_a aus C " << endl; }

};

class D : private A{
	
};

class F : /*default??*/ protected  A{ //Was wird standard mässig benutzt
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
		//a.public_m_a();//ok
	B b; 
		//b.private_m_a();//error
		//b.protected_m_a();//error
		//b.public_m_a();//ok
	//b.public_m_a(4711);//ok
	C c;
		//c.private_m_a();//error
		//c.protected_m_a();//error
		//c.public_m_a();//error, da diese Methode in C per protected Vererbung die Zurgriffskontrolle protected hat
//	D d;

	A * ap = &b;
	ap->public_m_a();
	//dynamic_cast<B*>(ap)->m();
	c.public_m_a();
	A* ac = &c;
	ac->public_m_a();
	A& ar = c;
	ar.public_m_a();
	B& br = c;
	br.public_m_a();
	br.public_m_a(1);
	return 0;
}