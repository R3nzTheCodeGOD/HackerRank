if __name__ == '__main__':
    s = input()
    resalnum = False
    resalpha = False
    resdigit = False
    reslower = False
    resupper = False
    for i in s:
        if(i.isalnum()):
            resalnum=True
        if(i.isalpha()):
            resalpha=True
        if(i.isdigit()):
            resdigit=True
        if(i.islower()):
            reslower=True
        if(i.isupper()):
            resupper=True
        
    print(resalnum)
    print(resalpha)
    print(resdigit)
    print(reslower)
    print(resupper)