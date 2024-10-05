
#include "RepoList.h"

RepoList::RepoList()
{
	numRepos = 0;
	list = new Repo *[MAX_ARRAY];
}

RepoList::~RepoList()
{
	delete[] list;
}

bool RepoList::add(Repo *p)
{
	if (numRepos >= MAX_ARRAY)
		return false;
	list[numRepos++] = p;
	return true;
}

Repo *RepoList::remove(int index)
{
	if (index < 0 || index >= numRepos)
		return nullptr;
	Repo *temp = list[index];
	numRepos--;
	for (int i = index; i < numRepos; i++)
	{
		list[i] = list[i + 1];
	}
	return temp;
}

Repo *RepoList::remove(string name)
{
	Repo *temp = nullptr;
	int i = 0;
	for (; i < numRepos; i++)
	{
		if (name == list[i]->getTitle())
		{
			temp = list[i];
			numRepos--;
			break;
		}
	}
	for (; i < numRepos; i++)
	{
		list[i] = list[i + 1];
	}
	return temp;
}

Repo *RepoList::get(int index)
{
	return (index < 0 || index >= numRepos) ? nullptr : list[index];
}

Repo *RepoList::get(string name)
{
	Repo *temp = nullptr;

	for (int i = 0; i < numRepos; i++)
	{
		if (list[i]->getTitle() == name)
		{
			temp = list[i];
			break;
		}
	}

	return temp;
}

void RepoList::clearAll()
{
	for (int i = 0; i < numRepos; i++)
	{
		delete list[i];
	}
	numRepos = 0;
}

bool RepoList::isFull()
{
	return numRepos >= MAX_ARRAY;
}

int RepoList::size()
{
	return numRepos;
}
