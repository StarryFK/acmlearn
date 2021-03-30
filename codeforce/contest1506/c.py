t = int(input().strip())
while t>0 :
    sa = input().strip()
    sb = input().strip()
    ok=0
    if(len(sa) > len(sb)):
        for i in range(len(sb), 0, -1):
            p=0
            while p+i<=len(sb):
                #print(sb[p:p+i], sa)
                if sb[p:p+i] in sa:
                    print(len(sb)+len(sa)-2*i)
                    ok=1

                    #print(sb[p:p+i])

                    break
                p+=1
            if ok==1:
                break
    else:
        for i in range(len(sa), 0, -1):
            p=0
            while p+i<=len(sa):
                #print(sb[p:p+i], sa)
                if sa[p:p+i] in sb:
                    print(len(sa)+len(sb)-2*i)
                    ok=1

                    #print(sa[p:p+i])

                    break
                p+=1
            if ok==1:
                break
    if ok==0:
        print(len(sa)+len(sb))
    t-=1


