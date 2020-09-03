s=input("문자열 입력:")

acronym=''
for word in s.upper().split():
        acronym=acronym+word[0]


print (acronym)
