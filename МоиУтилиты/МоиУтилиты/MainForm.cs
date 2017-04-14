using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace МоиУтилиты
{
    public partial class MainForm : Form
    {
        int count = 0;
        Random rand;
        char[] spec_chars = new char[] {'!','?','@','#','$','%','^','&','*','(',')'};
        Dictionary<string, double> metrica;
        public MainForm()
        {
            InitializeComponent();
            rand = new Random();
            metrica = new Dictionary<string, double>();
            metrica.Add("mm", 1);
            metrica.Add("cm", 10);
            metrica.Add("dm", 100);
            metrica.Add("m", 1000);
            metrica.Add("km", 1000000);
            metrica.Add("mile", 1609344);
        }

        private void MenuItemExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void MenuItemAbout_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Программа создана, чтобы быть ♥\nАвтор: Я", "О программе");
        }

        private void btnPlus_Click(object sender, EventArgs e)
        {
            count++;
            labelCount.Text = Convert.ToString(count);
        }

        private void btnMinus_Click(object sender, EventArgs e)
        {
            count--;
            labelCount.Text = Convert.ToString(count);
        }

        private void btnReset_Click(object sender, EventArgs e)
        {
            count = 0;
            labelCount.Text = Convert.ToString(count);
        }

        private void btnRand_Click(object sender, EventArgs e)
        {
            int n;
            n = rand.Next(Convert.ToInt32(genFrom.Value), Convert.ToInt32(genTo.Value));
            labelGenerate.Text = n.ToString();
            if (textBox1.Text.IndexOf(n.ToString()) == -1)
            {
                textBox1.AppendText(n + " ");
            }
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            textBox1.Clear();
        }

        private void btnCopy_Click(object sender, EventArgs e)
        {
            Clipboard.SetText(textBox1.Text);
        }

        private void MenuNoteAddDate_Click(object sender, EventArgs e)
        {
           note.AppendText(DateTime.Now.ToShortDateString() + " ");
        }

        private void MenuNoteAddTime_Click(object sender, EventArgs e)
        {
            note.AppendText(DateTime.Now.ToShortTimeString() + " ");
        }

        private void MenuNoteClear_Click(object sender, EventArgs e)
        {
            note.Clear();
        }

        private void MenuNoteSave_Click(object sender, EventArgs e)
        {
            try
            {
                note.SaveFile("node.txt");
            }
            catch
            {
                MessageBox.Show("Ошибка сохранения");
            }
        }

        private void MenuNoteLoad_Click(object sender, EventArgs e)
        {
            try
            {
                note.LoadFile("node.txt");
            }
            catch
            {
                MessageBox.Show("Ошибка записи");
            }
        }

        private void btnCreatePass_Click(object sender, EventArgs e)
        {
            if (clbOptions.CheckedItems.Count == 0) return;
            string pass = "";
            for (int i = 0; i < passLength.Value; i++)
            {
                int n = rand.Next(0, clbOptions.CheckedItems.Count);
                string s = clbOptions.CheckedItems[n].ToString();
                switch (s)
                {
                    case "Цифры": pass += rand.Next(10).ToString();
                        break;
                    case "Прописные буквы": pass += Convert.ToChar(rand.Next(65, 88));
                        break;
                    case "Строчные буквы": pass += Convert.ToChar(rand.Next(97, 122));
                        break;
                    case "Спец.символы": pass +=spec_chars[rand.Next(spec_chars.Length)];
                        break;
                }
                textBoxPass.Text = pass;
            }
        }

        private void tbFrom_TextChanged(object sender, EventArgs e)
        {
            double t1 = metrica[cbFrom.Text];
            double t2 = metrica[cbTo.Text];

            if (tbFrom.Text != "")
            {
                double n = Convert.ToDouble(tbFrom.Text);
                tbTo.Text = (n * t1 / t2).ToString();
            }

        }
    }
}
