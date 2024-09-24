from Crypto.Util.number import getPrime, bytes_to_long as b2l
from flag import FLAG

cat = """
                             .-.
                              \\ \\
                               \\ \\
                                | |
                                | |
              /\\---/\\   _,---._ | |
             /^   ^  \\,'       `. ;
            ( O   O   )           ;
             `.=o=__,'            \\
               /         _,--.__   \\
              /  _ )   ,'   `-. `-. \\
             / ,' /  ,'        \\ \\ \\ \\
            / /  / ,'          (,_)(,_)
           (,;  (,,)
"""


def main():

    bits = 1000

    p = getPrime(bits)
    q = getPrime(bits)

    maxNum = 2 << bits

    print(f"""Hello there!
I have encrypted my flag with an RSA primative. To prove I have knowledge of the
secrets, I will allow you to ask questions about p and q - both of which are {bits} bits long.
Specifically, you can ask me about p and q mod m where m is below a certain number.\n""")
    n = input("How many questions shall you ask? ")

    try:
        n = int(n)

    except:
        print(f"Must input a natural number. You've made the cat upset...\n{cat}")
        return

    if n <= 2 or n >= bits:
        print(f"You must ask at least three questions and no more than {bits}")
        return

    maxMod = 2 << (bits // n)

    print(f"With {n} questions, you can only ask for moduli upto {maxMod}.\n")

    for i in range(n):
        m = input(f"Question {i+1}: List your modulus: ")
        try:
            m = int(m)

        except:
            print(f"Must input a natural number. You've made the cat upset...\n{cat}")
            return

        if not (1 <= m <= maxMod):
            print(f"Must input a modulus between {1} and {maxMod}.")
            return

        print(f"p ≡ {p%m} (mod {m}), q ≡ {q%m} (mod {m})\n")


    n = p * q
    e = 65537
    l = (p-1)*(q-1)

    pt = b2l(FLAG)
    ct = pow(pt, e, n)


    print(f"No more questions. Here is the RSA encrypted flag:")
    print(f"n={n}\ne={e}\nct={ct}")



main()
