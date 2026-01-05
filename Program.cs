using System.Text;
string path = @"C:\tmp\PyKube.py";
string path2 = @"C:\tmp\PyKube.bat";
bool DoCleanTMPFiles = true;
int colorNumber = 2;
string KubeParts = "#";

Console.BackgroundColor = ConsoleColor.Black;
List<ConsoleColor> colorsList = new List<ConsoleColor>()
{
    ConsoleColor.Black,
    ConsoleColor.DarkBlue,
    ConsoleColor.DarkGreen,
    ConsoleColor.DarkCyan,
    ConsoleColor.DarkRed,
    ConsoleColor.DarkMagenta,
    ConsoleColor.DarkYellow,
    ConsoleColor.Gray,
    ConsoleColor.DarkGray,
    ConsoleColor.Blue,
    ConsoleColor.Green,
    ConsoleColor.Cyan,
    ConsoleColor.Red,
    ConsoleColor.Magenta,
    ConsoleColor.Yellow,
    ConsoleColor.White
};
string PyTranslatedColor = (@"'" + colorsList[colorNumber] + "'");
void changeColor()
{   
    
    
    var color = colorsList[colorNumber];



        Console.Clear();
        colorNumber++;
        Console.ForegroundColor = color;
         Console.WriteLine($"Change Color ? \n press enter for next\n Escape to continue \n Color : {color} color number : {colorNumber}");
        ConsoleKeyInfo key = Console.ReadKey(true);
        if (colorNumber > 15) { colorNumber = 0; changeColor(); }
    else
    {
        if (key.Key == ConsoleKey.Escape) { KubeBuilder(); }
        else { Console.Clear(); changeColor(); }
    }







}
void sayIt(string sayIt) { Console.Write(sayIt); }
void DoChangeColorASK()
{
    Console.WriteLine("Chage Kube Color ? Y/N");
    string userIntuptDoseWantToChnageColor = Console.ReadLine();
    if (userIntuptDoseWantToChnageColor == "Y") { changeColor(); }
    else if (userIntuptDoseWantToChnageColor == "y") { Console.Clear(); changeColor(); }
    else { KubeBuilder(); }
}

void KubePartsBuilder(){ Console.Write(KubeParts);}
Console.WriteLine("Enter the size of the cube X :");
int X = Convert.ToInt32(Console.ReadLine());
Console.Clear();
int staticX = X;
Console.WriteLine("Enter the size of the cube Y :");
int Y = Convert.ToInt32(Console.ReadLine());
int staticY = Y;
Console.Clear();
changeColor();
void KubeBuilder()
{
    colorNumber--;
    PyTranslatedColor = (@"'" + colorsList[colorNumber] + "'");
    Y = staticY;
    Console.Clear();
    while (Y != 0)
    {
        X = staticX * 2;
        KubeXbuilder();
        X = staticX*2;
        Y--;
        Thread.Sleep(10);
        Console.WriteLine("");
       
    }
    void KubeXbuilder()
    {
        while (X != 0)
        {
            X--;
            KubePartsBuilder();
        }
    }
    Console.WriteLine("\n Press Enter to Generate Final Cube ");
    Console.ReadLine();
/*    if (!System.IO.Directory.Exists(@"C:\\tmp"))
    {
        System.IO.Directory.CreateDirectory(@"C:\\tmp");
    }*/
    using (FileStream fs = File.Create(path))
    {
        byte[] info = new UTF8Encoding(true).GetBytes($"import turtle\r\n\r\nturtle.title('PyKube')\r\nfrom time import sleep\r\nturtle.color({PyTranslatedColor})\r\nfor i in range(2):\r\n    sleep(0.2)\r\n    turtle.begin_fill()\r\n    turtle.forward({staticX*10})\r\n    turtle.left(90)\r\n    turtle.forward({staticY * 10})\r\n    turtle.left(90)\r\n    sleep(0.2)\r\n    turtle.end_fill()\r\nturtle.penup()\r\nturtle.left(90)\r\nturtle.left(90)\r\nturtle.forward(1000)\r\nturtle.done()\r\n\r\n");
        fs.Write(info, 0, info.Length);
        fs.Flush();
        fs.Close();

      
    }
    using (FileStream fs = File.Create(path2))
    {
        byte[] info = new UTF8Encoding(true).GetBytes($"start {path} \n cd C://tmp \n del python-3.14.2-amd64.exe \n del dotnet-runtime-10.0.1-win-x64.exe ");
        fs.Write(info, 0, info.Length);
        fs.Flush();
        fs.Close();

        

    }
    System.Diagnostics.Process.Start(@"C:\tmp\PyKube.bat");
    if (DoCleanTMPFiles == true) {sayIt("Cleanig TMP files... "); Thread.Sleep(2000); File.Delete(path2); Thread.Sleep(5000); File.Delete(path);}
    else { Console.Beep(); Console.WriteLine(@"Data stored on C:\tmp"); Thread.Sleep(1000); File.Delete(path2); Console.Read();}
}
