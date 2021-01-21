def count_substring(s, ss):
    cnt=0
    len_s=len(s)
    len_ss=len(ss)
    for i in range(0,len_s):
        tmp=s[i:i+len_ss]
        if(tmp==ss):
            cnt=cnt+1
    return cnt

if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    count = count_substring(string, sub_string)
    print(count)