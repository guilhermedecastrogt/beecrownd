using System;

class Program
{
    static void Main()
    {
        // Time to go to sleep (9 PM)
        TimeSpan sleepTime = new TimeSpan(21, 0, 0);

        // Time to wake up (5 AM)
        TimeSpan wakeUpTime = new TimeSpan(5, 0, 0);

        // If wake-up time is earlier than sleep time, adjust for the next day
        if (wakeUpTime < sleepTime)
        {
            wakeUpTime = wakeUpTime.Add(new TimeSpan(24, 0, 0));
        }

        // Calculate the difference in time (sleep duration)
        TimeSpan sleepDuration = wakeUpTime - sleepTime;

        // Display the result in total hours
        Console.WriteLine($"You slept for {sleepDuration.TotalHours} hours.");
    }
}Q