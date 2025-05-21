using OpenTK.Graphics.OpenGL;
using OpenTK.Mathematics;
using Timer = System.Timers.Timer;

namespace OpenTKTest
{
    public partial class Form1 : Form
    {
        private Timer _renderTimer;

        private readonly float[] _vertices = {
            // 顶点位置       // 颜色
            -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, // 红色
            0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // 绿色
            0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // 蓝色
            -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 0.0f, // 黄色
            -0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 1.0f, // 品红
            0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 1.0f, // 青色
            0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, // 白色
            -0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 0.0f  // 黑色
        };

        private readonly uint[] _indices = {
            0, 1, 2, 2, 3, 0, // 后面
            4, 5, 6, 6, 7, 4, // 前面
            0, 4, 7, 7, 3, 0, // 左面
            1, 5, 6, 6, 2, 1, // 右面
            3, 2, 6, 6, 7, 3, // 上面
            0, 1, 5, 5, 4, 0  // 下面
        };

        private int _vbo;
        private int _vao;
        private int _ebo;
        private Matrix4 _projection;
        private Matrix4 _view;
        private float _rotationAngle;

        private int _program;

        private bool _isInit = false;

        public Form1()
        {
            InitializeComponent();

            glControl1.Load += InitGl;
            glControl1.Paint += GlControl1_Paint;

            _renderTimer = new Timer(16); // 60 FPS 16
            _renderTimer.Elapsed += (s, e) =>
            {
                glControl1.Invalidate();
            };
            _renderTimer.Start();
        }

        private void GlControl1_Paint(object? sender, PaintEventArgs e)
        {
            Render();
        }

        private void Render()
        {
            // 清屏
            GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);
            // 启用深度测试
            GL.Enable(EnableCap.DepthTest);
            // 更新模型矩阵
            _rotationAngle += 10.0f;
            //Matrix4 model = Matrix4.CreateRotationY(MathHelper.DegreesToRadians(_rotationAngle));
            Matrix4 model = Matrix4.CreateRotationY(MathHelper.DegreesToRadians(_rotationAngle));
            // 渲染
            GL.UseProgram(_program);
            GL.UniformMatrix4(GL.GetUniformLocation(_program, "model"), false, ref model);
            GL.UniformMatrix4(GL.GetUniformLocation(_program, "view"), false, ref _view);
            GL.UniformMatrix4(GL.GetUniformLocation(_program, "projection"), false, ref _projection);

            GL.BindVertexArray(_vao);
            GL.DrawElements(PrimitiveType.Triangles, _indices.Length, DrawElementsType.UnsignedInt, 0);

            glControl1.SwapBuffers();
        }

        public void InitGl(object? sender, EventArgs eventArgs)
        {
            // 初始化 OpenGL
            GL.ClearColor(Color4.Blue);

            // 创建 VBO、VAO 和 EBO
            _vao = GL.GenVertexArray();
            GL.BindVertexArray(_vao);

            _vbo = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ArrayBuffer, _vbo);
            GL.BufferData(BufferTarget.ArrayBuffer, _vertices.Length * sizeof(float), _vertices, BufferUsageHint.StaticDraw);

            _ebo = GL.GenBuffer();
            GL.BindBuffer(BufferTarget.ElementArrayBuffer, _ebo);
            GL.BufferData(BufferTarget.ElementArrayBuffer, _indices.Length * sizeof(uint), _indices, BufferUsageHint.StaticDraw);

            // 配置顶点属性
            GL.VertexAttribPointer(0, 3, VertexAttribPointerType.Float, false, 6 * sizeof(float), 0);
            GL.EnableVertexAttribArray(0);
            GL.VertexAttribPointer(1, 3, VertexAttribPointerType.Float, false, 6 * sizeof(float), 3 * sizeof(float));
            GL.EnableVertexAttribArray(1);

            // 加载 Shader
            _program = GL.CreateProgram();
            int vertShader = CompileShader(ShaderType.VertexShader, LoadShader("Shader.vert"));
            int fragShader = CompileShader(ShaderType.FragmentShader, LoadShader("Shader.frag"));
            GL.AttachShader(_program, vertShader);
            GL.AttachShader(_program, fragShader);
            GL.LinkProgram(_program);

            // 设置投影矩阵和视图矩阵
            _projection = Matrix4.CreatePerspectiveFieldOfView(MathHelper.DegreesToRadians(45.0f), 1, 0.1f, 100.0f);
            _view = Matrix4.CreateTranslation(0.0f, 0.0f, -3.0f);

            _isInit = true;
        }

        int CompileShader(ShaderType type, string source)
        {
            int shader = GL.CreateShader(type);
            GL.ShaderSource(shader, source);
            GL.CompileShader(shader);

            GL.GetShader(shader, ShaderParameter.CompileStatus, out int success);
            if (success == 0)
            {
                GL.GetShaderInfoLog(shader, out string info);
                throw new Exception($"{type} 编译失败: {info}");
            }

            return shader;
        }

        private string LoadShader(string path)
        {
            return File.ReadAllText(path);
        }


        private void button1_Click(object sender, EventArgs e)
        {
            Render();
        }

        private void glControl1_Click(object sender, EventArgs e)
        {

        }
    }
}
