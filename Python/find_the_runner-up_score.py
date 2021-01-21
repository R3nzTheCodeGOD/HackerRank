if __name__ == '__main__':
    n = int(raw_input())
    arr = map(int, raw_input().split())
    num_ar=list(map(int,arr))
    set_tmp=set(num_ar)
    final_ar=list(set_tmp)
    final_ar.sort()
    print final_ar[-2]