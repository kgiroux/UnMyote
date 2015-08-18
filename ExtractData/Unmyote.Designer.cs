namespace ExtractData
{
    partial class Unmyote
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
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
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Unmyote));
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.facebookPict = new System.Windows.Forms.PictureBox();
            this.TwitterPict = new System.Windows.Forms.PictureBox();
            this.YoutubePict = new System.Windows.Forms.PictureBox();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            this.GooglePict = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.facebookPict)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.TwitterPict)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.YoutubePict)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.GooglePict)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(45, 12);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(297, 89);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Click += new System.EventHandler(this.pictureBox1_Click);
            // 
            // facebookPict
            // 
            this.facebookPict.Image = ((System.Drawing.Image)(resources.GetObject("facebookPict.Image")));
            this.facebookPict.Location = new System.Drawing.Point(45, 154);
            this.facebookPict.Name = "facebookPict";
            this.facebookPict.Size = new System.Drawing.Size(56, 50);
            this.facebookPict.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.facebookPict.TabIndex = 1;
            this.facebookPict.TabStop = false;
            this.facebookPict.Click += new System.EventHandler(this.facebookPict_Click);
            // 
            // TwitterPict
            // 
            this.TwitterPict.Image = ((System.Drawing.Image)(resources.GetObject("TwitterPict.Image")));
            this.TwitterPict.Location = new System.Drawing.Point(125, 154);
            this.TwitterPict.Name = "TwitterPict";
            this.TwitterPict.Size = new System.Drawing.Size(56, 50);
            this.TwitterPict.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.TwitterPict.TabIndex = 2;
            this.TwitterPict.TabStop = false;
            this.TwitterPict.Click += new System.EventHandler(this.TwitterPict_Click);
            // 
            // YoutubePict
            // 
            this.YoutubePict.Image = ((System.Drawing.Image)(resources.GetObject("YoutubePict.Image")));
            this.YoutubePict.Location = new System.Drawing.Point(285, 154);
            this.YoutubePict.Name = "YoutubePict";
            this.YoutubePict.Size = new System.Drawing.Size(56, 50);
            this.YoutubePict.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.YoutubePict.TabIndex = 3;
            this.YoutubePict.TabStop = false;
            this.YoutubePict.Click += new System.EventHandler(this.YoutubePict_Click);
            // 
            // linkLabel1
            // 
            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Location = new System.Drawing.Point(115, 118);
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size(128, 13);
            this.linkLabel1.TabIndex = 5;
            this.linkLabel1.TabStop = true;
            this.linkLabel1.Text = "http://www.unmyote.com";
            this.linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel1_LinkClicked);
            // 
            // GooglePict
            // 
            this.GooglePict.Image = ((System.Drawing.Image)(resources.GetObject("GooglePict.Image")));
            this.GooglePict.Location = new System.Drawing.Point(205, 154);
            this.GooglePict.Name = "GooglePict";
            this.GooglePict.Size = new System.Drawing.Size(56, 50);
            this.GooglePict.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.GooglePict.TabIndex = 6;
            this.GooglePict.TabStop = false;
            this.GooglePict.Click += new System.EventHandler(this.GooglePict_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(117, 236);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(162, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "contact : contact@unmyote.com";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(292, 231);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 8;
            this.button1.Text = "Close";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // Unmyote
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(379, 261);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.GooglePict);
            this.Controls.Add(this.linkLabel1);
            this.Controls.Add(this.YoutubePict);
            this.Controls.Add(this.TwitterPict);
            this.Controls.Add(this.facebookPict);
            this.Controls.Add(this.pictureBox1);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Unmyote";
            this.Text = "Unmyote";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.facebookPict)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.TwitterPict)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.YoutubePict)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.GooglePict)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.PictureBox facebookPict;
        private System.Windows.Forms.PictureBox TwitterPict;
        private System.Windows.Forms.PictureBox YoutubePict;
        private System.Windows.Forms.LinkLabel linkLabel1;
        private System.Windows.Forms.PictureBox GooglePict;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button button1;
    }
}