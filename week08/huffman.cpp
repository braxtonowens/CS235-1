/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#include <iostream>        // for CIN and COUT
#include <fstream>         // for IFSTREAM
#include <cassert>         // for ASSERT
#include <string>          // for STRING: binary representation of codes
#include "bnode.h"         // for BINARY_NODE class definition
#include "vector.h"        // for VECTOR container
#include "pair.h"          // for PAIR container
#include "huffman.h"       // for HUFFMAN() prototype


using std::cout;
using std::cin;
using std::ifstream;
using std::endl;
using std::string;
using std::bad_alloc;
using namespace custom;
using namespace std;
using namespace custom;

vector<int> blacklist;
vector<int> order;

bool notBlacklisted(int index) {
	for (int i = 0; i < blacklist.size(); i++) {
		if (index == blacklist[i])
			return false;
	}
	return true;
}

int getLowest(vector<custom::pair<float, string>> pairs) {
    int index = 0;
    int i;
    for (i = 0; i < pairs.size(); i++) {
        if ((pairs[i].getFirst() < pairs[index].getFirst()) && notBlacklisted(i))
        {
            index = i;
        }
        if (blacklist.size()+1 == pairs.size()) 
        {
        	index = i;
        }

    }

    if (notBlacklisted(index))
    	blacklist.push_back(index);
    return index;
}

double sumOfNode(BNode<custom::pair<float, string>> *node) 
{
	double sum = 0;
	if (node->pLeft != NULL) 
	{
		cout << "left";
		sum += sumOfNode(node->pLeft);
	}
	if (node->pRight != NULL) 
	{
		cout << "right";
		sum += sumOfNode(node->pRight);
	}
	if (node->pRight == NULL && node->pLeft == NULL)
		return node->data.getFirst();
	else
		return sum;
}

void orderPairs(vector <custom::pair <float, string>> &pairs)
{
	vector <custom::pair <float, string>> temp(pairs);
	for (int i = 0; i < temp.size(); i++)
	{
		custom::pair <float, string> tempP(temp[0]);
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] < tempP) tempP = temp[i];
		}
	}
	pairs = temp;
}

void getHuffman(vector <custom::pair <float, string>> &pairs, 
	BNode <custom::pair<float, string>>* &tree)
{
	BNode <custom::pair<float, string>>* tree2 = new BNode <custom::pair<float, string>>;
	if (tree->data >)
}

/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(const string & fileName)
{
	//BNode<custom::pair<float, string>> *root = NULL;
	string word;
	float freq;
    vector <custom::pair <float, string>> pairs;
    ifstream myfile(fileName);

    if (myfile.fail())
    {
        cout << "Error reading file \"" << fileName << "\"\n";
        return;
    }

	if (myfile.is_open())
	{
		while (myfile >> word)
		{
			myfile >> freq;
			pairs.push_back(custom::pair<float, string>(freq, word));
		}
		myfile.close();
	}

	orderPairs(pairs);

	BNode <custom::pair<float, string>> * hTree = 
		new BNode <custom::pair<float, string>>(getHuffman(pairs));



   return;
}
