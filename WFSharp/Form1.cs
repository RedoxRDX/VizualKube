namespace WFSharp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }



        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)//rayKube
        {


            if (comboBox1.SelectedIndex == 0)
            {
                System.Diagnostics.Process.Start("CPPKube\\RayCPPKubeKonsole.exe");
            }
            else if (comboBox1.SelectedIndex == 1)
            {
                System.Diagnostics.Process.Start("CPPKube\\RayCPPKube.exe");
            }
            else { System.Diagnostics.Process.Start("CPPKube\\RayCPPKube.exe"); }

        }

        private void Noting_Click(object sender, EventArgs e)//CSKube
        {
            System.Diagnostics.Process.Start("CSKube\\VizualKube.exe");
        }

        private void button3_Click(object sender, EventArgs e)//Noting button
        {

        }

        private void domainUpDown1_SelectedItemChanged(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
/*            if (comboBox1.SelectedIndex == 0)
            {
                System.Diagnostics.Process.Start("CPPKube\\RayCPPKubeKonsole.exe");
            }
            else if (comboBox1.SelectedIndex == 1)
            {
                System.Diagnostics.Process.Start("CPPKube\\RayCPPKube.exe");
            }
          */
        }
    }
}