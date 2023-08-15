# Challenge description

## The Gold Pot

I left some of my hash browns out in the sun and now they're all rotten.
Now I wont be able to digest my messages :(
Flag format: quack{1_2_3}

unfu: pq13o6n6ns66so774snn589n9q18s906
ibti: bbc9f1ef16g38176g86e7b92cb337b8e
mfxm: 3899ihgfg79k92fk727h2190ggi8fgh5

# Solution

Find the hints in the description around hashing ROT ciphers and message digest 5. Using cyberchef or other means, use a rotation cipher of differing amounts on the three strings so they all say "hash" at the beginning. Then use rainbow table lookups (hinted in the title) or other md5 decryption sites to decipher the three hashes to rainbow, table and ninja. combine these three to form the flag

`quack{rainbow_table_ninja}`
