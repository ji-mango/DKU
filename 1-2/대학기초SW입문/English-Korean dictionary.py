english_dict=dict()

english_dict['one']='하나'
english_dict['two']='둘'
english_dict['three']='셋'
english_dict['four']='넷'
english_dict['name']='이름'

word=input("단어 입력:");
print(english_dict.get(word,'없음'))
