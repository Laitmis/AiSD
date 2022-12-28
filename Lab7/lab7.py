def sub_seq(arr, index, res):
    if (index == len(arr)):
        print(res)
        return

    sub_seq(arr, index + 1, res)
    sub_seq(arr, index + 1, res + [arr[index]])

def get_all_sub_seq(arr):
    sub_seq(arr, 0, [])

get_all_sub_seq([1, 2, 3])
