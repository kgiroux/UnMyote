using System;
using System.Drawing;
using System.IO;
using System.Windows.Forms;

namespace ExtractData
{
    public partial class Main : Form
    {
        public Main()
        {
            InitializeComponent();
        }

        private void Browse_Click(object sender, EventArgs e)
        {

            FolderBrowserDialog fbd = new FolderBrowserDialog();
            Console.WriteLine("PATH : " + Path.GetDirectoryName(Application.ExecutablePath));
            fbd.SelectedPath = Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().Location);
            DialogResult result = fbd.ShowDialog();
            string[] files = Directory.GetFiles(fbd.SelectedPath);

            Acquisition acq = new Acquisition(files, this);
            acq.StartReadFile();

            Graphic gph = new Graphic(acq);
            this.Hide();
            gph.Show();
            this.Close();

            
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


    }
}
