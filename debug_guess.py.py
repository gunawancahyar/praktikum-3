import random

def play(min_v=50, max_v=100):
    
    secret = random.randint(0, max_v)

    # DEBUG PRINT
    print(f"SECRET (BUG): {secret}")

    attempts = 0
    print(f"Tebak angka antara {min_v} sampai {max_v}!")

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

if __name__ == "__main__":
    play()