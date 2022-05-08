using System.Security.Cryptography;
using System.Text;

//var time = new DateTimeOffset(DateTime.UtcNow).ToUnixTimeMilliseconds() % 1234567891012;
var time = 1650586610263 % 1234567891012;
//Console.WriteLine(time.ToString());
//Console.WriteLine(((int)time).ToString());

Console.WriteLine("Is this even quackable?");
Random r = new Random((int)time);

using (var sha = new SHA512Managed())
{

    var flag = $"quack{sha.ComputeHash(Encoding.UTF32.GetBytes(time.ToString()))}_12345_party?";

    for (int i = 0; i < 30; i++)
    {
        var bytes = sha.ComputeHashEncoding.UTF32.GetBytes(r.NextDouble().ToString()));
        foreach (var b in bytes)
            Console.Write(b.ToString());

        Console.Write("\n");
    }
}
