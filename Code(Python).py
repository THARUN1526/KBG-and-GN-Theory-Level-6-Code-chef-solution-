def hel2(x,y):
    if x == y:
        return 0
    l = []
    for i in range(1,int(x**0.5)+1):
        if x%i == 0:
            l.append(i)
            l.append(x//i)
            if i*i == x:
                l.pop()
    l.sort(reverse=True)
    #print(l)
    cnt = 0
    prev = x
    for i in range(1,len(l)):
        if prev%l[i] == 0 and l[i]%y == 0:
            cnt += prev//l[i]
            #print(l[i])
            #print(cnt,prev)
            prev = l[i]
            if l[i] == y:
                break
    return cnt

def gcd(x,y):
    if x%y == 0:
        return y
    return gcd(y,x%y)

def fun(n,u,v):
    g = gcd(u,v)
    res1 = hel2(u,g)
    #print("res1 " + str(res1))
    res2 = hel2(v,g)
    #print("res2 " + str(res2))
    res = res1 + res2
    return res
    
for _ in range(int(input())):
    n,q = map(int,input().split())
    for _ in range(q):
        u,v = map(int,input().split())
        print(fun(n,u,v))
        