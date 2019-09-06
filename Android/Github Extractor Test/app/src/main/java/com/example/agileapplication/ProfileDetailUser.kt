package com.example.agileapplication
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import retrofit2.Call
import javax.security.auth.callback.Callback
//terminar aqui, tem erros
class ProfileDetailUser : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_profile_detail_user)
    }

    val call = RetrofitInitializer().reposService().list()
    call.enqueue(object: Callback<List<ReposService>?> {
        override fun onResponse(call: Call<List<ReposService>?>?,
                                response: Response<List<Note>?>?) {
        }

        override fun onFailure(call: Call<List<Note>?>?,
                               t: Throwable?) {
        }
    })




    val recyclerView = repos_list_recyclerview
    recyclerView.adapter = ReposListAdapter(repos(), this)
    // restante da configuração do recyclerView
}

private fun repos(): List<Repos> {
    // listas de exemplos
}
