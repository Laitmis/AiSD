import random

class HashTable:
    def __init__(self, capacity):
        self.table = [None for _ in range(capacity)]
        self.capacity = capacity
        self.size = 0

    def hashCode(self, x): return (2004 - x*x) % self.capacity

    def set(self, key, value):
        if self.size == self.capacity: raise ValueError('Hash Table is overflow')
        hashIndex = self.hashCode(key)

        while self.table[hashIndex] != None and self.table[hashIndex][0] != key:
            hashIndex = (hashIndex + 1) % self.capacity

        if self.table[hashIndex] == None:
            self.size += 1

        self.table[hashIndex] = (key, value)

    def delete(self, key):
        hashIndex = self.hashCode(key)

        for i in range(hashIndex, self.capacity):
            if not self.table[i]: continue

            if self.table[i][0] == key:
                self.table[i] = None
                return

        for i in range(hashIndex):
            if not self.table[i]: continue

            if self.table[i][0] == key:
                self.table[i] = None
                return

    def get(self, key):
        hashIndex = self.hashCode(key)

        for i in range(hashIndex, self.capacity):
            if not self.table[i]: continue
            if self.table[i][0] == key:
                return self.table[i][1]

        for i in range(hashIndex):
            if not self.table[i]: continue
            if self.table[i][0] == key:
                return self.table[i][1]

        return None

def count_collisions(hash_table : HashTable):
    count = 0
    counted_hash = []

    for i in range(hash_table.capacity):
        if not hash_table.table[i]: continue

        hashIndex = hash_table.hashCode(hash_table.table[i][0])
        if hashIndex in counted_hash: continue
        counted_hash.append(hashIndex)

    return hash_table.size - len(counted_hash)

def print_HashTable(hash_table : HashTable):
    for i in range(hash_table.capacity):
        if hash_table.table[i] and hash_table.table[i] != -1:
            print(hash_table.table[i])

if __name__ == "__main__":
    SIZE = 12

    hash_table = HashTable(SIZE)

    for _ in range(SIZE):
        key = random.randint(0, 57)
        hash_table.set(key, random.randint(102, 202))
        print(key, hash_table.hashCode(key))

    print_HashTable(hash_table)

    print('colisies:', count_collisions(hash_table))