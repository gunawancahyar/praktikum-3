import random
import time

def play(min_v, max_v):
    secret = random.randint(min_v, max_v)
    attempts = 0

    print(f"\nTebak angka antara {min_v} sampai {max_v}!")

    start = time.time()

    while True:
        try:
            guess = int(input("Masukkan tebakan: "))
        except ValueError:
            print("Input bukan angka, coba lagi.")
            continue

        attempts += 1

        if guess < secret:
            print("Terlalu kecil.")
        elif guess > secret:
            print("Terlalu besar.")
        else:
            print(f"Benar! {attempts} percobaan.")
            break

    end = time.time()
    print("Waktu:", round(end - start, 2), "detik")

    return attempts


def load_best():
    try:
        with open("best_score_py.txt", "r") as f:
            return int(f.read())
    except:
        return None


def save_best(score):
    with open("best_score_py.txt", "w") as f:
        f.write(str(score))


print("Pilih level:")
print("1. Easy (1-10)")
print("2. Medium (1-100)")
print("3. Hard (1-1000)")

try:
    level = int(input("Masukkan pilihan: "))
except ValueError:
    level = 2

if level == 1:
    min_v, max_v = 1, 10
elif level == 2:
    min_v, max_v = 1, 100
elif level == 3:
    min_v, max_v = 1, 1000
else:
    print("Level tidak valid, default medium")
    min_v, max_v = 1, 100

attempts = play(min_v, max_v)

best = load_best()

if best is None or attempts < best:
    print("Best score baru!")
    save_best(attempts)
else:
    print("Best score saat ini:", best)