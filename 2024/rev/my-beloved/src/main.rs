use std::io::{self, Error, Write};

const XOR_KEY: &str = "DUCKCTF2024";

const STR_SIZE: usize = 256;

const fn xor_impl(s: &str, key: &[u8]) -> [u8; STR_SIZE] {
    let mut result = [0u8; STR_SIZE];
    let bytes = s.as_bytes();
    let len = bytes.len();
    let key_len = key.len();
    let mut i = 0;

    while i < len {
        if bytes[i] != 0 {
            result[i] = bytes[i] ^ key[i % key_len];
        }
        i += 1;
    }
    result
}

macro_rules! xor {
    ($s:expr, $key:expr) => {
        xor_impl($s, $key)
    };
}

const ENCRYPTED: [u8; STR_SIZE] = xor!("quack{i_stole_this_from_fortnite}", XOR_KEY.as_bytes());
const IMAGE_DATA: &[u8] = include_bytes!("image.png");

fn main() -> Result<(), Error> {
    println!("password please!");

    let mut user_input = String::new();
    io::stdin().read_line(&mut user_input)?;

    user_input = user_input.trim().to_string();

    if xor_impl(&user_input, XOR_KEY.as_bytes()) == ENCRYPTED {
        println!("please enjoy this sacred art!");
        let mut file = std::fs::File::create("sacred_art.png")?;
        file.write_all(IMAGE_DATA)?;
    } else {
        println!(">:(");
    }

    Ok(())
}
