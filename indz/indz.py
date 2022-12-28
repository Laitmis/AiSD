import sys
t, n, _ = [int(a) for a in input().split()]

def get_place_index(list, the_num):
    i, j = len(list) * 1 // 3, len(list) * 2 // 3
    while True:
        print(list[i], the_num, list[j])
        m = int(input())
        if m == the_num:
            if j - i == 1:
                return j
            else:
                i, j = i + (j-i) * 1 // 3, i + (j-i) * 2 // 3
        elif m == list[i]:
            if i == 0:
                return 0
            elif j - i == 1:
                i, j = i - 1, i
            else:
                i, j = i-(j-i)*2//3, i-(j-i)*1//3
        else:
            if j == len(list) - 1:
                return len(list)
            elif j-i == 1:
                i, j = j, j + 1
            else:
                i, j = j + (j-i) * 1 // 3, j + (j-i) * 2 // 3
        if i == j:
            j += 1


while t > 0:
    print(1, 2, 3)
    l = int(input())
    if l == 1:
        list = [2, 1, 3]
    elif l == 2:
        list = [1, 2, 3]
    else:
        list = [1, 3, 2]
    while len(list) < n:
        next_i = len(list) + 1
        place_index = get_place_index(list, next_i)
        list.insert(place_index, next_i)

    print(' '.join(str(a) for a in list))
    ans = int(input())
    if ans == 1:
        pass
    if ans == -1:
        sys.exit()

    t -= 1
