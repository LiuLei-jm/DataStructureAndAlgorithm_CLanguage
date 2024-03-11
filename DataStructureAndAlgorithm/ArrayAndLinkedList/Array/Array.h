#ifndef _Array_H

int RandomAccess(int *nums, int size);
void Insert(int *nums, int size, int num, int index);
void RemoveItem(int *nums, int size, int index);
void Traverse(int *nums, int size);
int Find(int *nums, int size, int target);
int *Extend(int *nums, int size, int enlarge);

#endif