import re
#pattern = re.compile(r'\b[A-Z][a-z]+\b') -letters
#pattern = re.compile(r'[1-9][0-9]*')  #- numbers 
#pattern = re.compile(r"[A-Za-z0-9_\.]+@[a-z]+\.[a-z]+ ")
#pattern = re.compile(r"(+4)?[0-9]{10}") - nr tel 
pattern = re.compile(r"[0-9]*(\.?[0-9]*)?")
matches = pattern.finditer("12") 
for i in matches :
    print(i)
