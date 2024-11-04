
#ifndef REPOLIST_H
#define REPOLIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Repo.h"
#include "defs.h"

using namespace std;

class RepoList
{

public:
	// constructor
	RepoList();
	// copy constructor
	RepoList(RepoList &);

	// destructor
	~RepoList();

	// other
	bool add(Repo *);
	Repo *get(const string &title);
	Repo *get(int);
	Repo *remove(const string &title);
	Repo *remove(int);
	int size();
	bool isFull();
	void print();

private:
	class Node
	{
	public:
		Node *next;
		Node *prev;
		Repo *data;
	};
	Node *dummy;
	int numRepos;

	// helper functions
	Node *getNode(int index) const;
};
#endif
