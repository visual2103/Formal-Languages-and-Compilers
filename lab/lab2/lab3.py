import re 
pattern = re.compile(r"(([-+]?[1-9][0-9]*)?([-+]?[0-9]*i)?)|[0-9]|i |")

matches = pattern.finditer("3 i 30-i 4+2i 000+i 6i -4i 0") 
for i in matches :
    print(i.group())