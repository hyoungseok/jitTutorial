/**
  * Created by alex on 15/01/2019
  */

class EvalJNI {

  @native def loadModel(modelName: String): Long
  @native def evaluate(pModel: Long, x: Array[Float]): Array[Float]

}

object EvalJNI {

  def main(args: Array[String]): Unit = {
    System.load(s"${System.getProperty("user.dir")}/lib/libModel.dylib")

    val x = Array(1.0F, 1.0F, 1.0F)
    val eval = new EvalJNI
    val projectPath = System.getProperty("user.dir").split("/").dropRight(1).mkString("/")
    val pModel = eval.loadModel(s"${projectPath}/train_python/trace_model.pth")
    val prediction = eval.evaluate(pModel, x)

    println(s"model pointer: ${pModel}")
    println(s"prediction: ${prediction.mkString(",")}")
  }

}
