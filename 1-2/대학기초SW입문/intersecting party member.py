a=input("파티A명단:")
b=input("파티B명단:")

partyA=set()
partyB=set()

for s in a.split():
    partyA.add(s)

for s in b.split():
    partyB.add(s)


print("2개의 파티에 모두 참석한 사람은 다음과 같습니다.")
print(partyA.intersection(partyB))
