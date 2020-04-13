#include <string>
#include <ctime>
#include <utility>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Sequence
{
protected:
	double firstTerm;
public:
	Sequence(double fTrm)
	{
		firstTerm = fTrm;
	}
	double getfirstTerm()const { return firstTerm; }
	void setfirstTerm(double fTrm) { firstTerm = fTrm; }
	//Makes this class abstract
	virtual void displaySequence()const = 0;
	
};

class geometricSequence : public Sequence
{
public:
	geometricSequence(const double firstTerm, double cR) : Sequence(firstTerm)
	{
		 cRatio = cR;
	}
	double getCommonRatio()const { return cRatio; }
	void setCommonRatio(double cR) { cRatio = cR; }
	void displaySequence()const
	{
		Sequence::displaySequence();
		cout << "The next 4 terms in the geometric sequence are: ";
		double start = firstTerm;
		
		for (int i = 0; i < 4; i++)
		{
			start = start * cRatio;
			cout << start << " ";
		}
		cout << endl;
	}
private:
	double cRatio;

};
class arithmeticSequence : public Sequence
{
public:
	arithmeticSequence(const double firstTerm, double cD) : Sequence(firstTerm)
	{
		cDiff = cD;
	}
	double getCommonDiff()const { return cDiff; }
	void setCommonDiff(double cD) { cDiff = cD; }
	void displaySequence()const
	{
		Sequence::displaySequence();
		cout << "The next 4 terms in the arithmetic sequence are: ";
		double start = firstTerm;
		
		for (int i = 0; i < 4; i++)
		{
			start = start + cDiff;
			cout << start << " ";
		}
		cout << endl;

	}
	
private:
	double cDiff;
};
class FactorialSeq : public Sequence 
{
public: 
	FactorialSeq() :Sequence(1){}
	void displaySequence()const
	{
		cout << "The first 5 terms in the factorial sequence are 1, 1, 2, 6, 24" << endl;
	}

};
int main()
{
	arithmeticSequence a_seq(100, 10);
	geometricSequence  g_seq(50, .72);
	arithmeticSequence a_seq1(-3, 10);
	geometricSequence  g_seq1(0.5, 250);
	arithmeticSequence a_seq2(-1.5, 13.4);
	geometricSequence  g_seq2(-7, -14);
	FactorialSeq f_seq;


	Sequence* ptr;
	vector<Sequence*> seqVec;

	/*arithmeticSequence a(15, 3);
	geometricSequence b(15, 3);

	seqVec.push_back(&a_seq);
	seqVec.push_back(&g_seq);
	seqVec.push_back(&a_seq1);
	seqVec.push_back(&g_seq1);
	seqVec.push_back(&a_seq2);
	seqVec.push_back(&g_seq2);*/
	/*seqVec.push_back(&f_seq);

	for (size_t i = 0; i < seqVec.size(); i++)
	{
		seqVec[i]->displaySequence();
	}
*/
	 


	return 0;
}