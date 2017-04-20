
import numpy as np

#assigning values
values={0: 'a', 1: 'b', 2: 'c', 3: 'd', 4: 'e', 5: 'f', 6: 'g', 7: 'h', 8: 'i', 9: 'j', 10: 'k', 11: 'l', 12: 'm', 13: 'n', 14: 'o', 15: 'p', 16: 'q', 17: 'r', 18: 's', 19: 't', 20: 'u', 21: 'v', 22: 'w', 23: 'x', 24: 'y', 25: 'z'}
values1={'a': 0, 'b': 1, 'c': 2, 'd': 3, 'e': 4, 'f': 5, 'g': 6, 'h': 7, 'i': 8, 'j': 9, 'k': 10, 'l': 11, 'm': 12, 'n': 13, 'o': 14, 'p': 15, 'q': 16, 'r': 17, 's': 18, 't': 19, 'u': 20, 'v': 21, 'w': 22, 'x': 23, 'y': 24, 'z': 25 }

print("\n Toy Tetra Graph Hash")
print("-------------------------")
msg=input("\nenter the message  : ")   
l=len(msg)
if(l<16):
	for i in range(l,16):
		msg= msg + 'a'


arr = np.array([[]])
for i in msg:
	arr = np.append(arr,values1[i])

print("\nThe message is : ")

arr = arr.reshape(4,4)
print("\n",arr)                                                             
                                                                       #round1
t1=arr.sum(axis=0)%26
print("\nthe values after round1 are :")                                                      
print("\n",t1)
                                                                       #round2
a1 = a2 = a3= arr
a1 = np.roll(a1[0],3)
a2 = np.roll(a2[1],2)
a3 = np.roll(a3[2],5)
a4 = np.fliplr(arr)
a4 = np.roll(a4[3],4)

t2 = (a1+a2+a3+a4)%26
print("\nthe values after round2 are :")
print("\n",t2)

tn=(t1+t2)%26
t = np.array([])
for i in tn:
	t=np.append(t,values[i])

print("\nthe hash value is :")
print("\n",t)




