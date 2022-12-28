from draw_ import *

def merge(draw_info:DrawInformation, begin, middle, end):
    arr = draw_info.lst
    j = middle + 1
    if arr[middle] <= arr[middle + 1]:
        return

    while begin <= middle and j <= end:
        draw_list(draw_info, {begin: draw_info.BLUE, j: draw_info.BLUE}, clear_bg=True)

        if arr[begin] <= arr[j]:
            begin += 1
        else:
            draw_list(draw_info, {begin: draw_info.RED, j: draw_info.RED}, clear_bg=True)

            temp = arr[j]

            i = j
            while i != begin:
                arr[i] = arr[i-1]
                draw_list(draw_info, {begin: draw_info.RED, j: draw_info.RED}, clear_bg=True)
                i -= 1

            arr[begin] = temp
            draw_list(draw_info, {begin: draw_info.GREEN, j: draw_info.GREEN}, clear_bg=True)
            begin += 1
            middle += 1
            j += 1

def merge_sort(draw_info:DrawInformation, begin, end):
    
    if begin < end:
        middle = begin + (end - begin) // 2

        merge_sort(draw_info, begin, middle)
        merge_sort(draw_info, middle+1, end)

        merge(draw_info, begin, middle, end)

def main():
    clock = pygame.time.Clock()
    
    n = 100

    lst = generate_starting_list(n)
    print(lst)

    clock_tick = 800

    draw_info = DrawInformation(1000, 750, lst, clock_tick=clock_tick)
    
    draw(draw_info)
    
    run = True
    while run:
        for event in pygame.event.get():
            draw_list(draw_info, clear_bg=True)

            if event.type == pygame.QUIT:
                run = False
            if event.type != pygame.KEYDOWN:
                continue

            if event.key == pygame.K_r:
                lst = generate_starting_list(n)
                draw_info.set_list(lst)
            elif event.key == pygame.K_SPACE:
                merge_sort(draw_info, 0, len(draw_info.lst)-1)
                draw_list(draw_info)


    pygame.quit()

    print(lst)

if __name__ == '__main__':
    main()
