namespace WFSharp
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            label1 = new Label();
            RayKube = new Button();
            button3 = new Button();
            Noting = new Button();
            comboBox1 = new ComboBox();
            SuspendLayout();
            // 
            // label1
            // 
            resources.ApplyResources(label1, "label1");
            label1.FlatStyle = FlatStyle.System;
            label1.Name = "label1";
            label1.Click += label1_Click;
            // 
            // RayKube
            // 
            resources.ApplyResources(RayKube, "RayKube");
            RayKube.Name = "RayKube";
            RayKube.UseVisualStyleBackColor = true;
            RayKube.Click += button1_Click_1;
            // 
            // button3
            // 
            button3.Cursor = Cursors.No;
            resources.ApplyResources(button3, "button3");
            button3.Name = "button3";
            button3.UseVisualStyleBackColor = true;
            button3.Click += button3_Click;
            // 
            // Noting
            // 
            resources.ApplyResources(Noting, "Noting");
            Noting.Name = "Noting";
            Noting.UseVisualStyleBackColor = true;
            Noting.Click += Noting_Click;
            // 
            // comboBox1
            // 
            comboBox1.FormattingEnabled = true;
            comboBox1.Items.AddRange(new object[] { resources.GetString("comboBox1.Items"), resources.GetString("comboBox1.Items1") });
            resources.ApplyResources(comboBox1, "comboBox1");
            comboBox1.Name = "comboBox1";
            comboBox1.SelectedIndexChanged += comboBox1_SelectedIndexChanged;
            // 
            // Form1
            // 
            resources.ApplyResources(this, "$this");
            AutoScaleMode = AutoScaleMode.Font;
            Controls.Add(comboBox1);
            Controls.Add(Noting);
            Controls.Add(button3);
            Controls.Add(RayKube);
            Controls.Add(label1);
            FormBorderStyle = FormBorderStyle.FixedDialog;
            HelpButton = true;
            Name = "Form1";
            Load += Form1_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private Label label1;
        private Button RayKube;
        private Button button3;
        private Button Noting;
        private ComboBox comboBox1;
    }
}
