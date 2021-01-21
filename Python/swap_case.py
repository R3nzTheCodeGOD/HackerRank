def swap_case(s):
    newstring = ""
    
    for item in s:
        if item.isupper():
            newstring += item.lower()
        else:
            newstring += item.upper()
            
    return newstring

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)