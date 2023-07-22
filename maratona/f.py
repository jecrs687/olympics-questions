value_n, value_m= map(int,input("").split())
dna = input("")
protein = input("")
quant = int(input(""))
memoize = {}
dna_size= len(dna)
starts_memoized = {}
    
def calc_protein(x1,x2):
    global dna, protein, memoize;
    substring = protein[x1-1:x2]
    if starts_memoized.get(substring) is not None:
      return memoize[substring]
    result = 0
    size = len(substring)
    for i in range(dna_size):
      if(dna[i] == substring[0]):
        if(dna[i:i+size] == substring):
          result += 1
    memoize[substring] = result
    return result 

for i in range(quant):
  value = input("")
  values = value.split()
  key = values[0] +"_"+ values[1]
  x1, x2 = map(int,values)  
  print(calc_protein(x1,x2))
