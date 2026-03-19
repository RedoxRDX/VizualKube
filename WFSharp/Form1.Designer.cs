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
            label1 = new Label();
            RayKube = new Button();
            button3 = new Button();
            Noting = new Button();
            SuspendLayout();
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.FlatStyle = FlatStyle.System;
            label1.Font = new Font("JetBrains Mono", 8.999999F, FontStyle.Regular, GraphicsUnit.Point, 0);
            label1.Location = new Point(125, 9);
            label1.Name = "label1";
            label1.Size = new Size(140, 16);
            label1.TabIndex = 1;
            label1.Text = "VKube SharpLauncher";
            label1.TextAlign = ContentAlignment.TopCenter;
            label1.Click += label1_Click;
            // 
            // RayKube
            // 
            RayKube.Location = new Point(12, 202);
            RayKube.Name = "RayKube";
            RayKube.Size = new Size(360, 45);
            RayKube.TabIndex = 2;
            RayKube.Text = "RayKube";
            RayKube.UseVisualStyleBackColor = true;
            RayKube.Click += button1_Click_1;
            // 
            // button3
            // 
            button3.Cursor = Cursors.No;
            button3.Enabled = false;
            button3.Location = new Point(12, 304);
            button3.Name = "button3";
            button3.Size = new Size(360, 45);
            button3.TabIndex = 4;
            button3.Text = "Nothing here YET";
            button3.UseVisualStyleBackColor = true;
            // 
            // Noting
            // 
            Noting.Location = new Point(12, 253);
            Noting.Name = "Noting";
            Noting.Size = new Size(360, 45);
            Noting.TabIndex = 5;
            Noting.Text = "button4";
            Noting.UseVisualStyleBackColor = true;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(384, 361);
            Controls.Add(Noting);
            Controls.Add(button3);
            Controls.Add(RayKube);
            Controls.Add(label1);
            FormBorderStyle = FormBorderStyle.FixedDialog;
            ImeMode = ImeMode.Disable;
            Name = "Form1";
            Text = "VKube CSL";
            Load += Form1_Load;
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private Label label1;
        private Button RayKube;
        private Button button3;
        private Button Noting;
    }
}
