using System;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace ExtractData
{
    public partial class Main : Form
    {
        private int val;
        private int lenghtFileList;
        private Graphic gph;
        public Main()
        {
            InitializeComponent();
            val = 1;
        }

        private void Browse_Click(object sender, EventArgs e)
        {

            FolderBrowserDialog fbd = new FolderBrowserDialog();
            Console.WriteLine("PATH : " + Path.GetDirectoryName(Application.ExecutablePath));
            fbd.SelectedPath = Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
            DialogResult result = fbd.ShowDialog();
            string[] files = Directory.GetFiles(fbd.SelectedPath);

            //lenghtFileList = files.Length;
           
            int NBdata = 8 + 4 + 3 + 3 + 3;
            lenghtFileList = NBdata;
           //ReadingProgressBar.Maximum = files.Length +7;
           ReadingProgressBar.Maximum = NBdata;
            ReadingProgressBar.Minimum = 0;

            Acquisition acq = new Acquisition(files, this);
            acq.StartReadFile();

            gph = new Graphic(acq,this);
            
        }


        public void updateProgressBar()
        {
            ReadingProgressBar.Invoke(new updatebar(this.UpdateProgress));
        }

        public delegate void updatebar();

        private void UpdateProgress()
        {
            ReadingProgressBar.Value += val;
            this.updateConsoleLog("val : " + lenghtFileList, -1);
            this.updateConsoleLog("maximum : " + ReadingProgressBar.Maximum,-1);
            if (lenghtFileList == ReadingProgressBar.Maximum)
            {
                gph.Show();
            }
        }



    public void updateConsoleLog(string text, int type)
        {
            /* Création d'une méthode sécurisé (pointeur sur une fonction) pour changer le contenu de la liste. Cette méthode est anonyme*/
            Func<int> del = delegate ()
            {
                Color color;
                /* Rajoute du texte à la texte box */
                switch (type)
                {
                    case 0:
                        color = Color.Black;
                        break;
                    case 1:
                        color = Color.Green;
                        break;
                    case -1:
                        color = Color.Red;
                        break;
                    default:
                        color = Color.Black;
                        break;
                }
                Log.SelectionStart = Log.TextLength;
                Log.SelectionLength = 0;
                Log.SelectionColor = color;
                Log.AppendText(text + System.Environment.NewLine);
                Log.SelectionColor = Log.ForeColor;
                return 0;
            };
            try
            {
                Invoke(del);
            }
            catch (System.InvalidOperationException ex)
            {
                Console.WriteLine(ex.Message);
            }
        }

        private void Main_FormClosing(object sender, FormClosingEventArgs e)
        {
            Application.Exit();
        }

        private void Main_FormClosed(object sender, FormClosedEventArgs e)
        {
            Application.Exit();
        }
    }
}
