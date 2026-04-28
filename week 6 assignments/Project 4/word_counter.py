# Project 4 — Word Counter
# Concepts: Strings, Loops, Dictionaries

# Kullanıcıdan cümleyi alıyoruz
sentence = input("Enter a sentence: ")

# Küçük harfe çevirip kelimelere ayırıyoruz (.split())
words = sentence.lower().split()

# 1. Toplam kelime sayısını bulma
total_words = len(words)

# 2. Boşluklar hariç toplam karakter sayısını bulma
# .replace(" ", "") metindeki tüm boşlukları siler
total_chars = len(sentence.replace(" ", ""))

# 3. Kelime frekansını (hangi kelime kaç kere geçmiş) hesaplama
# Bir sözlük (dictionary) kullanıyoruz
frequency = {}

for word in words:
    if word in frequency:
        frequency[word] += 1 # Kelime zaten varsa sayısını 1 artır
    else:
        frequency[word] = 1  # Kelime ilk kez görüldüyse 1 olarak kaydet

# Sonuçları ekrana yazdırma
print(f"Total words: {total_words}")
print(f"Total characters (no spaces): {total_chars}")
print("Word frequency:")
for word, count in frequency.items():
    print(f"  {word}  -> {count}")
