package com.example.todolist

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import android.widget.EditText
import android.widget.ImageButton
import android.widget.LinearLayout
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import android.widget.Toast
import android.graphics.Color
import androidx.appcompat.widget.SwitchCompat

class MainActivity : AppCompatActivity(){
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val list: LinearLayout = findViewById(R.id.list)
        val main: LinearLayout = findViewById(R.id.main)
        val switch: SwitchCompat = findViewById(R.id.Switch)
        val create: ImageButton = findViewById(R.id.create)
        val delete: ImageButton = findViewById(R.id.delete)
        val title: TextView = findViewById(R.id.textView)
        val check: ImageButton = findViewById(R.id.check)
        val elements: ArrayList<LinearLayout> = ArrayList()
        var index = -1

        create.setOnClickListener {

            val newLinearLayout = LinearLayout(this).apply {
                layoutParams = LinearLayout.LayoutParams(
                    ViewGroup.LayoutParams.MATCH_PARENT,
                    resources.getDimensionPixelSize(R.dimen.height)
                )
                isClickable = true
                orientation = LinearLayout.HORIZONTAL
            }
            newLinearLayout.setBackgroundColor(Color.TRANSPARENT)
            elements.add(newLinearLayout)


            newLinearLayout.setOnClickListener {
                for (i in 0 until list.childCount) {
                    val child = list.getChildAt(i)
                    child.clearFocus()
                    child.setBackgroundColor(Color.TRANSPARENT)
                }
                index = elements.indexOf(newLinearLayout)
                newLinearLayout.setBackgroundColor(Color.DKGRAY)

            }

            delete.setOnClickListener {
                if (index != -1) {
                    list.removeView(elements[index])
                    index = -1
                } else {
                    Toast.makeText(this, "Please Select a Task", Toast.LENGTH_SHORT).show()
                }
            }

            main.setOnClickListener {
                newLinearLayout.setBackgroundColor(Color.TRANSPARENT)
                index = -1
                for (i in 0 until list.childCount) {
                    val child = list.getChildAt(i)
                    child.clearFocus()
                }
            }

            val checkbox = ImageView(this).apply {
                layoutParams = LinearLayout.LayoutParams(
                    resources.getDimensionPixelSize(R.dimen.width),
                    ViewGroup.LayoutParams.MATCH_PARENT,
                    0.4f
                )
                tag = "unchecked"
            }
            checkbox.setImageResource(R.drawable.checkbox)

            check.setOnClickListener {
                if (index != -1) {
                    for (i in 0 until elements[index].childCount) {
                        val element = elements[index].getChildAt(i)
                        if (element is ImageView) {
                            val tagValue = element.tag
                            if (tagValue == "checked") {
                                element.setImageResource(R.drawable.checkbox)
                                elements[index].setBackgroundColor(Color.TRANSPARENT)
                                element.tag = "unchecked"
                            } else {
                                element.setImageResource(R.drawable.checkbox_ticked)
                                elements[index].setBackgroundColor(Color.TRANSPARENT)
                                element.tag = "checked"
                            }
                        }
                        break
                    }
                    index = -1
                } else {
                    Toast.makeText(this, "Please Select a Task", Toast.LENGTH_SHORT).show()
                }
            }

            val textBox = EditText(this).apply {
                hint = "Enter Task"
                layoutParams = LinearLayout.LayoutParams(
                    ViewGroup.LayoutParams.WRAP_CONTENT,
                    ViewGroup.LayoutParams.MATCH_PARENT,
                    2.8f
                )
                textSize = 32f
                setTextColor(Color.DKGRAY)
            }

            val color = ImageView(this).apply {
                layoutParams = LinearLayout.LayoutParams(
                    resources.getDimensionPixelSize(R.dimen.width),
                    ViewGroup.LayoutParams.MATCH_PARENT,
                    0.4f
                )
                tag = "color"
            }
            color.setImageResource(R.drawable.empty)

            val cyan: ImageButton = findViewById(R.id.cyan)
            val magenta: ImageButton = findViewById(R.id.magenta)
            val red: ImageButton = findViewById(R.id.red)
            val lime: ImageButton = findViewById(R.id.lime)
            val yellow: ImageButton = findViewById(R.id.yellow)
            val cross: ImageButton = findViewById(R.id.cross)

            cyan.setOnClickListener {
                if (index != -1) {
                    for (i in 0 until elements[index].childCount) {
                        val element = elements[index].getChildAt(i)
                        if (element is ImageView) {
                            val tagValue = element.tag
                            if (tagValue == "color") {
                                element.setImageResource(R.drawable.cyan)
                                elements[index].setBackgroundColor(Color.TRANSPARENT)
                            }
                        }
                    }
                    index = -1
                } else {
                    Toast.makeText(this, "Please Select a Task", Toast.LENGTH_SHORT).show()
                }
            }
            magenta.setOnClickListener {
                if (index != -1) {
                    for (i in 0 until elements[index].childCount) {
                        val element = elements[index].getChildAt(i)
                        if (element is ImageView) {
                            val tagValue = element.tag
                            if (tagValue == "color") {
                                element.setImageResource(R.drawable.magenta)
                                elements[index].setBackgroundColor(Color.TRANSPARENT)
                            }
                        }
                    }
                    index = -1
                } else {
                    Toast.makeText(this, "Please Select a Task", Toast.LENGTH_SHORT).show()
                }
            }
            red.setOnClickListener {
                if (index != -1) {
                    for (i in 0 until elements[index].childCount) {
                        val element = elements[index].getChildAt(i)
                        if (element is ImageView) {
                            val tagValue = element.tag
                            if (tagValue == "color") {
                                element.setImageResource(R.drawable.red)
                                elements[index].setBackgroundColor(Color.TRANSPARENT)
                            }
                        }
                    }
                    index = -1
                } else {
                    Toast.makeText(this, "Please Select a Task", Toast.LENGTH_SHORT).show()
                }
            }
            lime.setOnClickListener {
                if (index != -1) {
                    for (i in 0 until elements[index].childCount) {
                        val element = elements[index].getChildAt(i)
                        if (element is ImageView) {
                            val tagValue = element.tag
                            if (tagValue == "color") {
                                element.setImageResource(R.drawable.lime)
                                elements[index].setBackgroundColor(Color.TRANSPARENT)
                            }
                        }
                    }
                    index = -1
                } else {
                    Toast.makeText(this, "Please Select a Task", Toast.LENGTH_SHORT).show()
                }
            }
            yellow.setOnClickListener {
                if (index != -1) {
                    for (i in 0 until elements[index].childCount) {
                        val element = elements[index].getChildAt(i)
                        if (element is ImageView) {
                            val tagValue = element.tag
                            if (tagValue == "color") {
                                element.setImageResource(R.drawable.yellow)
                                elements[index].setBackgroundColor(Color.TRANSPARENT)
                            }
                        }
                    }
                    index = -1
                } else {
                    Toast.makeText(this, "Please Select a Task", Toast.LENGTH_SHORT).show()
                }
            }
            cross.setOnClickListener {
                if (index != -1) {
                    for (i in 0 until elements[index].childCount) {
                        val element = elements[index].getChildAt(i)
                        if (element is ImageView) {
                            val tagValue = element.tag
                            if (tagValue == "color") {
                                element.setImageResource(R.drawable.empty)
                                elements[index].setBackgroundColor(Color.TRANSPARENT)
                            }
                        }
                    }
                    index = -1
                } else {
                    Toast.makeText(this, "Please Select a Task", Toast.LENGTH_SHORT).show()
                }
            }

            newLinearLayout.addView(checkbox)
            newLinearLayout.addView(textBox)
            newLinearLayout.addView(color)
            list.addView(newLinearLayout)
        }

        switch.setOnCheckedChangeListener { _, isChecked ->
            if (isChecked) {
                main.setBackgroundColor(Color.LTGRAY)
                title.setTextColor(Color.BLACK)
                switch.setTextColor(Color.BLACK)
            } else {
                main.setBackgroundColor(Color.BLACK)
                title.setTextColor(Color.WHITE)
                switch.setTextColor(Color.WHITE)
            }
        }
    }
}
