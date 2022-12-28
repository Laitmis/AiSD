#include "list.cpp"

struct TListIterator {
   TListItem *pointer;
};

TListIterator initTListIterator() {
   TListIterator tmp;
   tmp.pointer = NULL;
   return tmp;
}

bool isValid(TListIterator it) { return it.pointer != NULL; }

void moveNext(TListIterator &it) {
   if(isValid(it)) {
      it.pointer = it.pointer->next;
   }
   return;
}

void movePrev(TListIterator &it) {
   if(isValid(it)) {
      it.pointer = it.pointer->prev;
   }
   return;
}

string getValue(const TListIterator &it) {
   if(isValid(it)) {
      return it.pointer->value;
   }
   return 0;
}

void setValue(const TListIterator &it, string value) {
   if (isValid(it)) {
      it.pointer->value = value;
   }
   return;
}

TListIterator getBegin(TList l) {
   TListIterator tmp;
   tmp.pointer = l.first;
   return tmp;
}

TListIterator getEnd(TList l) {
   TListIterator tmp;
   tmp.pointer = l.last;
   return tmp;
}

void insertAfter(TList &l, const TListIterator &it, string value) {
   if (!isValid(it)) return;

   TListItem *tmp = new TListItem;
   tmp->value = value;
   tmp->next = it.pointer->next;

   if (it.pointer->next != NULL) { it.pointer->next->prev = tmp; }
   it.pointer->next = tmp;
   if (it.pointer == l.last) { l.last = tmp ;}

   return;
}

void insertBefore(TList &l, const TListIterator &it, string value) {
   if (!isValid(it)) return;

   TListItem *tmp = new TListItem;
   tmp->value = value;
   tmp->prev = it.pointer->prev;

   if (it.pointer->prev != NULL) { it.pointer->next->prev = tmp; }
   it.pointer->prev = tmp;
   if (it.pointer == l.first) { l.first = tmp ;}
   
   return;
}

void deleteListItem(TList &l, TListIterator &it) {
   if (!isValid(it)) return;

   if (it.pointer == l.first) { l.first = it.pointer->next; }
   if (it.pointer == l.last) { l.last = it.pointer->prev; }

   TListItem *next = it.pointer->next;
   TListItem *prev = it.pointer->prev;

   delete it.pointer;
   it.pointer = next;
   
   if (prev != NULL) { prev->next = next; }
   if (next != NULL) { next->prev = prev; }

   if (l.first == NULL) {l.last = NULL; }
   if (l.last == NULL) {l.first = NULL; }

   return;
}