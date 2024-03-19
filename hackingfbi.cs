Console.ForegroundColor = ConsoleColor.Green;
Console.BackgroundColor = ConsoleColor.Black;

int c = 0;
for (int i = 1; i <= 200; i = Random.Shared.Next(i+1, i + 10))
{
    if (i > 100) i = 100;
    Console.WriteLine($"Hacking FBI Database... {i}%");
    Thread.Sleep(Random.Shared.Next(50, 200));
    c = i;
    if (i == 100) break;
}

Console.WriteLine("Hacking FBI Database Successful!");
