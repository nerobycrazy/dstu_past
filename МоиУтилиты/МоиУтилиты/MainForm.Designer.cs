namespace МоиУтилиты
{
    partial class MainForm
    {
        /// <summary>
        /// Требуется переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Обязательный метод для поддержки конструктора - не изменяйте
        /// содержимое данного метода при помощи редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.MenuItemFile = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuItemExit = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuItemHelp = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuItemAbout = new System.Windows.Forms.ToolStripMenuItem();
            this.cnvrt = new System.Windows.Forms.TabControl();
            this.Counter = new System.Windows.Forms.TabPage();
            this.tabRand = new System.Windows.Forms.TabPage();
            this.btnPlus = new System.Windows.Forms.Button();
            this.btnMinus = new System.Windows.Forms.Button();
            this.btnReset = new System.Windows.Forms.Button();
            this.labelCount = new System.Windows.Forms.Label();
            this.genFrom = new System.Windows.Forms.NumericUpDown();
            this.genTo = new System.Windows.Forms.NumericUpDown();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.labelGenerate = new System.Windows.Forms.Label();
            this.btnRand = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.btnClear = new System.Windows.Forms.Button();
            this.btnCopy = new System.Windows.Forms.Button();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.note = new System.Windows.Forms.RichTextBox();
            this.блокнотToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuNoteAddDate = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuNoteAddTime = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripSeparator();
            this.MenuNoteSave = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuNoteLoad = new System.Windows.Forms.ToolStripMenuItem();
            this.MenuNoteClear = new System.Windows.Forms.ToolStripMenuItem();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.clbOptions = new System.Windows.Forms.CheckedListBox();
            this.passLength = new System.Windows.Forms.NumericUpDown();
            this.label3 = new System.Windows.Forms.Label();
            this.btnCreatePass = new System.Windows.Forms.Button();
            this.textBoxPass = new System.Windows.Forms.TextBox();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.cbFrom = new System.Windows.Forms.ComboBox();
            this.cbTo = new System.Windows.Forms.ComboBox();
            this.tbTo = new System.Windows.Forms.TextBox();
            this.tbFrom = new System.Windows.Forms.TextBox();
            this.menuStrip1.SuspendLayout();
            this.cnvrt.SuspendLayout();
            this.Counter.SuspendLayout();
            this.tabRand.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.genFrom)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.genTo)).BeginInit();
            this.tabPage1.SuspendLayout();
            this.tabPage2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.passLength)).BeginInit();
            this.tabPage3.SuspendLayout();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuItemFile,
            this.MenuItemHelp,
            this.блокнотToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(467, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // MenuItemFile
            // 
            this.MenuItemFile.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuItemExit});
            this.MenuItemFile.Name = "MenuItemFile";
            this.MenuItemFile.Size = new System.Drawing.Size(48, 20);
            this.MenuItemFile.Text = "Файл";
            // 
            // MenuItemExit
            // 
            this.MenuItemExit.Name = "MenuItemExit";
            this.MenuItemExit.Size = new System.Drawing.Size(152, 22);
            this.MenuItemExit.Text = "Выход";
            this.MenuItemExit.Click += new System.EventHandler(this.MenuItemExit_Click);
            // 
            // MenuItemHelp
            // 
            this.MenuItemHelp.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuItemAbout});
            this.MenuItemHelp.Name = "MenuItemHelp";
            this.MenuItemHelp.Size = new System.Drawing.Size(68, 20);
            this.MenuItemHelp.Text = "Помощь";
            // 
            // MenuItemAbout
            // 
            this.MenuItemAbout.Name = "MenuItemAbout";
            this.MenuItemAbout.Size = new System.Drawing.Size(152, 22);
            this.MenuItemAbout.Text = "О программе";
            this.MenuItemAbout.Click += new System.EventHandler(this.MenuItemAbout_Click);
            // 
            // cnvrt
            // 
            this.cnvrt.Controls.Add(this.Counter);
            this.cnvrt.Controls.Add(this.tabRand);
            this.cnvrt.Controls.Add(this.tabPage1);
            this.cnvrt.Controls.Add(this.tabPage2);
            this.cnvrt.Controls.Add(this.tabPage3);
            this.cnvrt.Dock = System.Windows.Forms.DockStyle.Fill;
            this.cnvrt.Location = new System.Drawing.Point(0, 24);
            this.cnvrt.Name = "cnvrt";
            this.cnvrt.SelectedIndex = 0;
            this.cnvrt.Size = new System.Drawing.Size(467, 346);
            this.cnvrt.TabIndex = 1;
            // 
            // Counter
            // 
            this.Counter.Controls.Add(this.labelCount);
            this.Counter.Controls.Add(this.btnReset);
            this.Counter.Controls.Add(this.btnMinus);
            this.Counter.Controls.Add(this.btnPlus);
            this.Counter.Location = new System.Drawing.Point(4, 22);
            this.Counter.Name = "Counter";
            this.Counter.Padding = new System.Windows.Forms.Padding(3);
            this.Counter.Size = new System.Drawing.Size(459, 320);
            this.Counter.TabIndex = 0;
            this.Counter.Text = "Счетчик";
            this.Counter.UseVisualStyleBackColor = true;
            // 
            // tabRand
            // 
            this.tabRand.BackColor = System.Drawing.Color.Silver;
            this.tabRand.Controls.Add(this.btnCopy);
            this.tabRand.Controls.Add(this.btnClear);
            this.tabRand.Controls.Add(this.textBox1);
            this.tabRand.Controls.Add(this.btnRand);
            this.tabRand.Controls.Add(this.labelGenerate);
            this.tabRand.Controls.Add(this.label2);
            this.tabRand.Controls.Add(this.label1);
            this.tabRand.Controls.Add(this.genFrom);
            this.tabRand.Controls.Add(this.genTo);
            this.tabRand.Location = new System.Drawing.Point(4, 22);
            this.tabRand.Name = "tabRand";
            this.tabRand.Padding = new System.Windows.Forms.Padding(3);
            this.tabRand.Size = new System.Drawing.Size(459, 320);
            this.tabRand.TabIndex = 1;
            this.tabRand.Text = "Генератор";
            // 
            // btnPlus
            // 
            this.btnPlus.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnPlus.Font = new System.Drawing.Font("Impact", 25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.btnPlus.Location = new System.Drawing.Point(301, 6);
            this.btnPlus.Name = "btnPlus";
            this.btnPlus.Size = new System.Drawing.Size(150, 150);
            this.btnPlus.TabIndex = 0;
            this.btnPlus.Text = "+";
            this.btnPlus.UseVisualStyleBackColor = true;
            this.btnPlus.Click += new System.EventHandler(this.btnPlus_Click);
            // 
            // btnMinus
            // 
            this.btnMinus.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnMinus.Font = new System.Drawing.Font("Impact", 25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.btnMinus.Location = new System.Drawing.Point(301, 162);
            this.btnMinus.Name = "btnMinus";
            this.btnMinus.Size = new System.Drawing.Size(150, 150);
            this.btnMinus.TabIndex = 1;
            this.btnMinus.Text = "-";
            this.btnMinus.UseVisualStyleBackColor = true;
            this.btnMinus.Click += new System.EventHandler(this.btnMinus_Click);
            // 
            // btnReset
            // 
            this.btnReset.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnReset.Font = new System.Drawing.Font("Impact", 25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.btnReset.Location = new System.Drawing.Point(6, 162);
            this.btnReset.Name = "btnReset";
            this.btnReset.Size = new System.Drawing.Size(289, 150);
            this.btnReset.TabIndex = 2;
            this.btnReset.Text = "Сброс";
            this.btnReset.UseVisualStyleBackColor = true;
            this.btnReset.Click += new System.EventHandler(this.btnReset_Click);
            // 
            // labelCount
            // 
            this.labelCount.AutoSize = true;
            this.labelCount.Font = new System.Drawing.Font("Monotype Corsiva", 60F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelCount.Location = new System.Drawing.Point(108, 31);
            this.labelCount.Name = "labelCount";
            this.labelCount.Size = new System.Drawing.Size(77, 97);
            this.labelCount.TabIndex = 3;
            this.labelCount.Text = "0";
            // 
            // genFrom
            // 
            this.genFrom.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.genFrom.Location = new System.Drawing.Point(32, 15);
            this.genFrom.Maximum = new decimal(new int[] {
            1000000,
            0,
            0,
            0});
            this.genFrom.Name = "genFrom";
            this.genFrom.Size = new System.Drawing.Size(108, 22);
            this.genFrom.TabIndex = 2;
            this.genFrom.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            // 
            // genTo
            // 
            this.genTo.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.genTo.Location = new System.Drawing.Point(33, 50);
            this.genTo.Maximum = new decimal(new int[] {
            1000000,
            0,
            0,
            0});
            this.genTo.Name = "genTo";
            this.genTo.Size = new System.Drawing.Size(107, 22);
            this.genTo.TabIndex = 3;
            this.genTo.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(8, 19);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(18, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "от";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(8, 54);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(19, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "до";
            // 
            // labelGenerate
            // 
            this.labelGenerate.AutoSize = true;
            this.labelGenerate.Font = new System.Drawing.Font("Monotype Corsiva", 27.75F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelGenerate.Location = new System.Drawing.Point(24, 87);
            this.labelGenerate.Name = "labelGenerate";
            this.labelGenerate.Size = new System.Drawing.Size(36, 45);
            this.labelGenerate.TabIndex = 6;
            this.labelGenerate.Text = "0";
            this.labelGenerate.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // btnRand
            // 
            this.btnRand.BackColor = System.Drawing.Color.Transparent;
            this.btnRand.Cursor = System.Windows.Forms.Cursors.Hand;
            this.btnRand.Font = new System.Drawing.Font("Showcard Gothic", 24F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnRand.Location = new System.Drawing.Point(144, 15);
            this.btnRand.Margin = new System.Windows.Forms.Padding(1);
            this.btnRand.Name = "btnRand";
            this.btnRand.Size = new System.Drawing.Size(309, 57);
            this.btnRand.TabIndex = 7;
            this.btnRand.Text = "Generate!";
            this.btnRand.UseVisualStyleBackColor = false;
            this.btnRand.Click += new System.EventHandler(this.btnRand_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(144, 76);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(307, 56);
            this.textBox1.TabIndex = 8;
            // 
            // btnClear
            // 
            this.btnClear.Location = new System.Drawing.Point(144, 138);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(109, 47);
            this.btnClear.TabIndex = 9;
            this.btnClear.Text = "Clear";
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // btnCopy
            // 
            this.btnCopy.Location = new System.Drawing.Point(259, 138);
            this.btnCopy.Name = "btnCopy";
            this.btnCopy.Size = new System.Drawing.Size(109, 47);
            this.btnCopy.TabIndex = 10;
            this.btnCopy.Text = "Copy";
            this.btnCopy.UseVisualStyleBackColor = true;
            this.btnCopy.Click += new System.EventHandler(this.btnCopy_Click);
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.note);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Size = new System.Drawing.Size(459, 320);
            this.tabPage1.TabIndex = 2;
            this.tabPage1.Text = "Блокнот";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(61, 4);
            // 
            // note
            // 
            this.note.Dock = System.Windows.Forms.DockStyle.Fill;
            this.note.Location = new System.Drawing.Point(0, 0);
            this.note.Name = "note";
            this.note.Size = new System.Drawing.Size(459, 320);
            this.note.TabIndex = 3;
            this.note.Text = "";
            // 
            // блокнотToolStripMenuItem
            // 
            this.блокнотToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.MenuNoteAddDate,
            this.MenuNoteAddTime,
            this.MenuNoteClear,
            this.toolStripMenuItem1,
            this.MenuNoteSave,
            this.MenuNoteLoad});
            this.блокнотToolStripMenuItem.Name = "блокнотToolStripMenuItem";
            this.блокнотToolStripMenuItem.Size = new System.Drawing.Size(65, 20);
            this.блокнотToolStripMenuItem.Text = "Блокнот";
            // 
            // MenuNoteAddDate
            // 
            this.MenuNoteAddDate.Name = "MenuNoteAddDate";
            this.MenuNoteAddDate.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift) 
            | System.Windows.Forms.Keys.D)));
            this.MenuNoteAddDate.Size = new System.Drawing.Size(232, 22);
            this.MenuNoteAddDate.Text = "Вставить дату";
            this.MenuNoteAddDate.Click += new System.EventHandler(this.MenuNoteAddDate_Click);
            // 
            // MenuNoteAddTime
            // 
            this.MenuNoteAddTime.Name = "MenuNoteAddTime";
            this.MenuNoteAddTime.ShortcutKeys = ((System.Windows.Forms.Keys)(((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.Shift) 
            | System.Windows.Forms.Keys.T)));
            this.MenuNoteAddTime.Size = new System.Drawing.Size(232, 22);
            this.MenuNoteAddTime.Text = "Вставить время";
            this.MenuNoteAddTime.Click += new System.EventHandler(this.MenuNoteAddTime_Click);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(229, 6);
            // 
            // MenuNoteSave
            // 
            this.MenuNoteSave.Name = "MenuNoteSave";
            this.MenuNoteSave.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
            this.MenuNoteSave.Size = new System.Drawing.Size(232, 22);
            this.MenuNoteSave.Text = "Сохранить";
            this.MenuNoteSave.Click += new System.EventHandler(this.MenuNoteSave_Click);
            // 
            // MenuNoteLoad
            // 
            this.MenuNoteLoad.Name = "MenuNoteLoad";
            this.MenuNoteLoad.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.L)));
            this.MenuNoteLoad.Size = new System.Drawing.Size(232, 22);
            this.MenuNoteLoad.Text = "Загрузить";
            this.MenuNoteLoad.Click += new System.EventHandler(this.MenuNoteLoad_Click);
            // 
            // MenuNoteClear
            // 
            this.MenuNoteClear.Name = "MenuNoteClear";
            this.MenuNoteClear.Size = new System.Drawing.Size(232, 22);
            this.MenuNoteClear.Text = "Очистить";
            this.MenuNoteClear.Click += new System.EventHandler(this.MenuNoteClear_Click);
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.textBoxPass);
            this.tabPage2.Controls.Add(this.btnCreatePass);
            this.tabPage2.Controls.Add(this.label3);
            this.tabPage2.Controls.Add(this.passLength);
            this.tabPage2.Controls.Add(this.clbOptions);
            this.tabPage2.Location = new System.Drawing.Point(4, 22);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Size = new System.Drawing.Size(459, 320);
            this.tabPage2.TabIndex = 3;
            this.tabPage2.Text = "Пароли";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // clbOptions
            // 
            this.clbOptions.CheckOnClick = true;
            this.clbOptions.FormattingEnabled = true;
            this.clbOptions.Items.AddRange(new object[] {
            "Цифры",
            "Строчный буквы",
            "Прописные буквы",
            "Спец.символы"});
            this.clbOptions.Location = new System.Drawing.Point(73, 75);
            this.clbOptions.Name = "clbOptions";
            this.clbOptions.Size = new System.Drawing.Size(160, 64);
            this.clbOptions.TabIndex = 0;
            // 
            // passLength
            // 
            this.passLength.Location = new System.Drawing.Point(320, 84);
            this.passLength.Maximum = new decimal(new int[] {
            64,
            0,
            0,
            0});
            this.passLength.Minimum = new decimal(new int[] {
            6,
            0,
            0,
            0});
            this.passLength.Name = "passLength";
            this.passLength.Size = new System.Drawing.Size(64, 20);
            this.passLength.TabIndex = 1;
            this.passLength.Value = new decimal(new int[] {
            6,
            0,
            0,
            0});
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(239, 86);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(79, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Длина пароля";
            // 
            // btnCreatePass
            // 
            this.btnCreatePass.Location = new System.Drawing.Point(239, 116);
            this.btnCreatePass.Name = "btnCreatePass";
            this.btnCreatePass.Size = new System.Drawing.Size(145, 23);
            this.btnCreatePass.TabIndex = 3;
            this.btnCreatePass.Text = "Создать пароль";
            this.btnCreatePass.UseVisualStyleBackColor = true;
            this.btnCreatePass.Click += new System.EventHandler(this.btnCreatePass_Click);
            // 
            // textBoxPass
            // 
            this.textBoxPass.Font = new System.Drawing.Font("Impact", 20.25F, System.Drawing.FontStyle.Italic, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.textBoxPass.Location = new System.Drawing.Point(97, 163);
            this.textBoxPass.Name = "textBoxPass";
            this.textBoxPass.Size = new System.Drawing.Size(269, 40);
            this.textBoxPass.TabIndex = 4;
            this.textBoxPass.Text = "Пароль";
            this.textBoxPass.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.tbFrom);
            this.tabPage3.Controls.Add(this.tbTo);
            this.tabPage3.Controls.Add(this.cbTo);
            this.tabPage3.Controls.Add(this.cbFrom);
            this.tabPage3.Location = new System.Drawing.Point(4, 22);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(459, 320);
            this.tabPage3.TabIndex = 4;
            this.tabPage3.Text = "Конвертер";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // cbFrom
            // 
            this.cbFrom.FormattingEnabled = true;
            this.cbFrom.Items.AddRange(new object[] {
            "mm",
            "cm",
            "dm",
            "m",
            "km",
            "mile"});
            this.cbFrom.Location = new System.Drawing.Point(230, 31);
            this.cbFrom.Name = "cbFrom";
            this.cbFrom.Size = new System.Drawing.Size(121, 21);
            this.cbFrom.TabIndex = 0;
            this.cbFrom.Text = "mm";
            // 
            // cbTo
            // 
            this.cbTo.FormattingEnabled = true;
            this.cbTo.Items.AddRange(new object[] {
            "mm",
            "cm",
            "dm",
            "m",
            "km",
            "mile"});
            this.cbTo.Location = new System.Drawing.Point(230, 58);
            this.cbTo.Name = "cbTo";
            this.cbTo.Size = new System.Drawing.Size(121, 21);
            this.cbTo.TabIndex = 1;
            this.cbTo.Text = "mm";
            // 
            // tbTo
            // 
            this.tbTo.Location = new System.Drawing.Point(55, 59);
            this.tbTo.Name = "tbTo";
            this.tbTo.ReadOnly = true;
            this.tbTo.Size = new System.Drawing.Size(169, 20);
            this.tbTo.TabIndex = 2;
            // 
            // tbFrom
            // 
            this.tbFrom.Location = new System.Drawing.Point(55, 32);
            this.tbFrom.Name = "tbFrom";
            this.tbFrom.Size = new System.Drawing.Size(169, 20);
            this.tbFrom.TabIndex = 3;
            this.tbFrom.TextChanged += new System.EventHandler(this.tbFrom_TextChanged);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(467, 370);
            this.Controls.Add(this.cnvrt);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "MainForm";
            this.Text = "Мои утилиты";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.cnvrt.ResumeLayout(false);
            this.Counter.ResumeLayout(false);
            this.Counter.PerformLayout();
            this.tabRand.ResumeLayout(false);
            this.tabRand.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.genFrom)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.genTo)).EndInit();
            this.tabPage1.ResumeLayout(false);
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.passLength)).EndInit();
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem MenuItemFile;
        private System.Windows.Forms.ToolStripMenuItem MenuItemExit;
        private System.Windows.Forms.ToolStripMenuItem MenuItemHelp;
        private System.Windows.Forms.ToolStripMenuItem MenuItemAbout;
        private System.Windows.Forms.TabControl cnvrt;
        private System.Windows.Forms.TabPage Counter;
        private System.Windows.Forms.Label labelCount;
        private System.Windows.Forms.Button btnReset;
        private System.Windows.Forms.Button btnMinus;
        private System.Windows.Forms.Button btnPlus;
        private System.Windows.Forms.TabPage tabRand;
        private System.Windows.Forms.NumericUpDown genFrom;
        private System.Windows.Forms.NumericUpDown genTo;
        private System.Windows.Forms.Button btnRand;
        private System.Windows.Forms.Label labelGenerate;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button btnCopy;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.RichTextBox note;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem блокнотToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem MenuNoteAddDate;
        private System.Windows.Forms.ToolStripMenuItem MenuNoteAddTime;
        private System.Windows.Forms.ToolStripSeparator toolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem MenuNoteSave;
        private System.Windows.Forms.ToolStripMenuItem MenuNoteLoad;
        private System.Windows.Forms.ToolStripMenuItem MenuNoteClear;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.CheckedListBox clbOptions;
        private System.Windows.Forms.TextBox textBoxPass;
        private System.Windows.Forms.Button btnCreatePass;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.NumericUpDown passLength;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.TextBox tbFrom;
        private System.Windows.Forms.TextBox tbTo;
        private System.Windows.Forms.ComboBox cbTo;
        private System.Windows.Forms.ComboBox cbFrom;
    }
}

