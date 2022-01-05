
import numpy as np
import matplotlib.pyplot as mat

def graph(val, t, array):
#val, t are same as in nuclei_table()
#array -- diff name for "table" variable
     parent = []
     daughter = [] 
     X=np.arange(0,t)

     for i in range(t):
         P = 0
         for j in range(val):
             if array[j][i] != 0:
                 P+=1
                    
         parent.append(P)
         daughter.append(30-P) 
     
     for i in range(t):
         if parent[i+1]<=15:
             p1 = parent[i]
             p2 = parent[i+1]
             time = i
             break


     slope = (p2 - p1)
     ht = ((val/2) + (time*slope) - p1) / slope
     print('Half-Lifetime is ', ht)

     p = np.array(parent)
     d = np.array(daughter)
     
     mat.plot(X, p, color = 'b', label = 'Parent')
     mat.plot(X, d, color = 'g', label = 'Daughter')
     mat.plot(ht, val/2, 'ro')
     mat.xlabel("Time Intervals")
     mat.ylabel("No. of Nuclei")
     mat.title("Radioactive Decay")
     mat.legend()

     mat.show()

def nuclei_table(val,t,prob):
#number of nuclei -- val
#time intrevals -- t
#probability of daughter nuclei formation -- prob

#defining a random array
    rand_array = np.random.rand(val,t)

    array = np.round(rand_array,2)


    for i in range(val):
        for j in range(t):
            if array[i][j] < prob:
                array[i][j+1:] = 0
                
    return array
    
#storage space for arrays    
mem = []

def start():
    print("hello there welcome to the nuclei table generator :)")
    print("input your values")
    val = input("enter the number of nuclei you're generating:")
    t = input("enter the time intreval for which you're generating:")
    prob = input("enter the probability for splitting of parent nuclei:")
    try :
        val = int(val)
        prob = float(prob)
        t = int(t)
    except:
        print("incorrect input given")
        print("restarting\n\n\n")
        start()
        
    print("generating the table")
    print("#" * 100)
    print("\n\n\n")
    table = nuclei_table(val,t,prob)
    print(table)
    #adding the generated table to log
    mem.append(table) 
    print("\n\n\n")
    print("#" * 20)
    
    graph(val, t, table)
    
    res = input("would you like to generate again?(1/0): ")
    if res == 1 or res == "yes":
        start()
    else:
        print("thank you")
    
start()    
    
    
    

    
    
