// Degree: MSc Computing Science
// Module: COMP70036 Object Oriented Design and Programming
// Add all of your answers to question 2 to this file.

/* The declarations of the class template ’list’ are below.
 
template <typename T> class list {
  public:
    list(); // constructor that creates an empty list
    void add(const T& item); // adds item to the end of the list
    int size(); // returns the number of items 
    // return constant iterators:
    list<T>::constant_iterator cbegin(); // the beginning of the list
    list<T>::constant_iterator cend(); // the end of the list
};
*/

#include<iostream>
#include<string>

using namespace std; 

/* Add your code below this line. */

class Test; 
class SerologyTest; 
class PCRTest; 

class HealthProfessional;
class Nurses;
class Pharmacists; 

class Test {
  public:
  virtual std::string getType() const = 0;
  virtual double getCost() const = 0;
  virtual bool detectsVirus() const = 0;

}; 

class SerologyTest: public Test {
  public:
  virtual string getType() const override {
    return "Serology"; 
  }

  virtual double getCost() const override {
    return 50; 
  }

  virtual bool detectsVirus() const override {
    return false; 
  }
}; 


class PCRTest: public Test {
  private:
  int cost; 
  bool sequenceVirus; 

  public:

  PCRTest(int _cost, bool _sequenceVirus) {
    cost = _cost;
    sequenceVirus = _sequenceVirus; 
  }

  void setCost(int _cost) {
    cost = _cost; 
  }

  virtual string getType() const override {
    return "PCR"; 
  }

  virtual double getCost() const override {
    if (sequenceVirus == true) {
      return 2 * cost; 
    }
    else {
      return cost;
    } 
  }

  virtual bool detectsVirus() const override {
    return false; 
  }

}; 

class HealthProfessional {
  protected: 
  string name; 
  int years_of_exp;
  int base_salary; 
  int totalTestCost = 0; 

  public: 
  virtual int getSalary(double totalTestsCost) const = 0; 

  int administeredTest(Test _test) {
    cost = _test.getCost; 
    totalTestCost += cost; 
  }
};
class Nurses: public HealthProfessional {
  public: 
  Nurses(string _name, int _years_of_exp, int _base_salary){
    name = _name;
    years_of_exp = _years_of_exp;
    base_salary = _base_salary; 
  }

  virtual int getSalary() const override {
    return base_salary + 100 * years_of_exp + 0.2 * totalTestCost; 
  }

};

class Pharmacists : public HealthProfessional {
  public: 
  Pharmacists(string _name, int _years_of_exp, int _base_salary){
    name = _name;
    years_of_exp = _years_of_exp;
    base_salary = _base_salary; 
  }
  virtual int getSalary() const override {
    return base_salary + 100 * years_of_exp + 0.1 * totalTestCost; 
  }

};

// Question b

// Question c

int main() {

  //create nurses 
  HealthProfessional *p = new Nurses("Paula", 5, 20000); 
  HealthProfessional *s = new Pharmacists("Sara" 10, 25000); 

  Test *serologyTest = new SerologyTest(); 
  Test *pcr1 = new PCRTest(90, false); 
  Test *pcr2 = new PCRTest(150, true); 

  p.administeredTest(pcr1); 
  p.administeredTest(serologyTest); 
  s.administeredTest(pcr2); 

  cout << "Yearly salary of Paula is" << p.getSalary(); 
  cout << "Yearly salary of Sara is" << s.getSalary(); 

  delete p, s, pcr1, pcr2, serologyTest; 

  return 0; 

}
