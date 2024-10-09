
#ifndef REPOLIST_H
#define REPOLIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Repo.h"
#include "defs.h"

using namespace std;

// TODO make this a linked list

class RepoList {
		
	public:
		//constructor
		RepoList();
		//copy constructor
		RepoList(RepoList&);
		
		//destructor
		~RepoList();
		
		//other
		bool add(Repo*);
		Repo* get(const string& title) ;
		Repo* get(int) ;
		Repo* remove(const string& title);
		Repo* remove(int);
		int size();
		bool isFull();
		void print();
	
	private:
		int numRepos;
		Repo** repos;
};
#endif
