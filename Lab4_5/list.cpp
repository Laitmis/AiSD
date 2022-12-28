#include <iostream>
using namespace std;

struct TListItem
{
   string value;
   TListItem *next, *prev;
};

struct TList
{
   TListItem *first, *last;
};

TList initList()
{
   TList l;
   l.first = NULL;
   l.last = NULL;

   return l;
}

bool isEmpty(TList &list) { return list.first == NULL; }

TListItem *makeTListItem(string value = "", TListItem *next = NULL, TListItem *prev = NULL)
{
   TListItem *newItem = new TListItem;
   newItem->value = value;
   newItem->next = next;
   newItem->prev = prev;

   return newItem;
}

void push(TList &list, string value)
{
   if (list.first == NULL)
   {
      list.first = new TListItem;
      list.first->value = value;
      list.first->next = NULL;
      list.first->prev = NULL;
      list.last = list.first;
      return;
   }

   list.last->next = makeTListItem(value, NULL, list.last);
   list.last = list.last->next;
}

void destroyList(TList &list)
{
   TListItem *itemToDelete = list.first;
   TListItem *tmp;
   while (itemToDelete != NULL)
   {
      tmp = itemToDelete->next;
      delete itemToDelete;
      itemToDelete = tmp;
   }

   list.first = list.last = NULL;
}

void printList(TList list)
{
   TListItem *tmp = list.first;
   while (tmp != NULL)
   {
      cout << tmp->value << " ";
      tmp = tmp->next;
   }
   cout << "\n";
}